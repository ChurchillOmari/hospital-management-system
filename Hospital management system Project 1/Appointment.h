#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Appointment {

private:

    int appointmentId;

    int patientId;

    int doctorId;

    string appointmentDate;

    string appointmentTime;

    string status;

public:

    Appointment();

    void inputAppointment();

    void displayAppointment() const;

    int getAppointmentId() const;

    int getPatientId() const;

    int getDoctorId() const;

    string getDate() const;

    string getTime() const;

    void cancelAppointment();

    void saveToFile(ofstream &out);

    void loadFromFile(ifstream &in);
};

#endif
