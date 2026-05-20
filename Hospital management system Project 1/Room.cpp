#include "Room.h"

Room::Room() {

    roomNumber = 0;

    wardType = "";

    occupied = false;

    patientId = -1;
}

void Room::addRoom() {

    cout << "\n===== ADD ROOM =====\n";

    cout << "Enter Room Number: ";
    cin >> roomNumber;

    cin.ignore();

    cout << "Enter Ward Type (General/ICU/VIP): ";
    getline(cin, wardType);

    occupied = false;

    patientId = -1;
}

void Room::displayRoom() const {

    cout << "\n=========================\n";

    cout << "Room Number : "
         << roomNumber << endl;

    cout << "Ward Type   : "
         << wardType << endl;

    cout << "Status      : "
         << (occupied ? "Occupied" : "Available")
         << endl;

    if (occupied) {

        cout << "Patient ID  : "
             << patientId << endl;
    }
}

int Room::getRoomNumber() const {

    return roomNumber;
}

bool Room::isOccupied() const {

    return occupied;
}

int Room::getPatientId() const {

    return patientId;
}

void Room::admitPatient(int pid) {

    occupied = true;

    patientId = pid;
}

void Room::dischargePatient() {

    occupied = false;

    patientId = -1;
}

string Room::getWardType() const {

    return wardType;
}

void Room::saveToFile(ofstream &out) {

    out << roomNumber << endl;

    out << wardType << endl;

    out << occupied << endl;

    out << patientId << endl;
}

void Room::loadFromFile(ifstream &in) {

    in >> roomNumber;

    in.ignore();

    getline(in, wardType);

    in >> occupied;

    in >> patientId;

    in.ignore();
}
