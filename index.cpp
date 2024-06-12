#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bus {
public:
    string busNumber;
    string driverName;
    string arrivalTime;
    string departureTime;
    string from;
    string to;
    vector<string> seats;

    Bus(string busNum, string driver, string arrival, string departure, string start, string destination)
        : busNumber(busNum), driverName(driver), arrivalTime(arrival), departureTime(departure), from(start), to(destination) {
        seats.resize(32, "Empty");  // Initializing 32 seats as empty
    }

    void showBusDetails() {
        cout << "Bus Number: " << busNumber << endl;
        cout << "Driver Name: " << driverName << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "From: " << from << endl;
        cout << "To: " << to << endl;
        cout << "Seats: " << endl;
        for (int i = 0; i < seats.size(); i++) {
            cout << "Seat " << i + 1 << ": " << seats[i] << endl;
        }
    }

    void reserveSeat(int seatNumber, string passengerName) {
        if (seatNumber < 1 || seatNumber > 32) {
            cout << "Invalid seat number!" << endl;
            return;
        }
        if (seats[seatNumber - 1] == "Empty") {
            seats[seatNumber - 1] = passengerName;
            cout << "Seat reserved successfully for " << passengerName << endl;
        } else {
            cout << "Seat is already reserved!" << endl;
        }
    }
};

class BusReservationSystem {
private:
    vector<Bus> buses;

public:
    void addBus() {
        string busNum, driver, arrival, departure, start, destination;
        cout << "Enter bus number: ";
        cin >> busNum;
        cout << "Enter driver's name: ";
        cin >> driver;
        cout << "Enter arrival time: ";
        cin >> arrival;
        cout << "Enter departure time: ";
        cin >> departure;
        cout << "Enter starting location: ";
        cin >> start;
        cout << "Enter destination: ";
        cin >> destination;

        Bus newBus(busNum, driver, arrival, departure, start, destination);
        buses.push_back(newBus);
        cout << "Bus added successfully!" << endl;
    }

    void showAllBuses() {
        if (buses.empty()) {
            cout << "No buses available!" << endl;
            return;
        }

        for (auto& bus : buses) {
            bus.showBusDetails();
            cout << "---------------------------------" << endl;
        }
    }

    void reserveSeat() {
        string busNum;
        int seatNumber;
        string passengerName;

        cout << "Enter bus number: ";
        cin >> busNum;
        auto it = find_if(buses.begin(), buses.end(), [&](Bus& bus) { return bus.busNumber == busNum; });

        if (it == buses.end()) {
            cout << "Bus not found!" << endl;
            return;
        }

        cout << "Enter seat number (1-32): ";
        cin >> seatNumber;
        cout << "Enter passenger's name: ";
        cin >> passengerName;

        it->reserveSeat(seatNumber, passengerName);
    }
};

int main() {
    BusReservationSystem system;
    int choice;

    while (true) {
        cout << "1. Add Bus" << endl;
        cout << "2. Show All Buses" << endl;
        cout << "3. Reserve Seat" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addBus();
            break;
        case 2:
            system.showAllBuses();
            break;
        case 3:
            system.reserveSeat();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
