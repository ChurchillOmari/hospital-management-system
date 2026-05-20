#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Room {

private:

    int roomNumber;

    string wardType;

    bool occupied;

    int patientId;

public:

    Room();

    void addRoom();

    void displayRoom() const;

    int getRoomNumber() const;

    bool isOccupied() const;

    int getPatientId() const;

    void admitPatient(int pid);

    void dischargePatient();

    string getWardType() const;

    void saveToFile(ofstream &out);

    void loadFromFile(ifstream &in);
};

#endif
