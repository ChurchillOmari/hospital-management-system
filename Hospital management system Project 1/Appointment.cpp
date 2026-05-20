#include "Appointment.h"

Appointment::Appointment() {

    appointmentId = 0;

    patientId = 0;

    doctorId = 0;

    appointmentDate = "";

    appointmentTime = "";

    status = "Scheduled";
}

void Appointment::inputAppointment() {

    cout << "\n===== BOOK APPOINTMENT =====\n";

    cout << "Enter Appointment ID: ";
    cin >> appointmentId;

    cout << "Enter Patient ID: ";
    cin >> patientId;

    cout << "Enter Doctor ID: ";
    cin >> doctorId;

    cin.ignore();

    cout << "Enter Date (DD/MM/YYYY): ";
    getline(cin, appointmentDate);

    cout << "Enter Time: ";
    getline(cin, appointmentTime);

    status = "Scheduled";
}

void Appointment::displayAppointment() const {

    cout << "\n=========================\n";

    cout << "Appointment ID : "
         << appointmentId << endl;

    cout << "Patient ID     : "
         << patientId << endl;

    cout << "Doctor ID      : "
         << doctorId << endl;

    cout << "Date           : "
         << appointmentDate << endl;

    cout << "Time           : "
         << appointmentTime << endl;

    cout << "Status         : "
         << status << endl;
}

int Appointment::getAppointmentId() const {

    return appointmentId;
}

int Appointment::getPatientId() const {

    return patientId;
}

int Appointment::getDoctorId() const {

    return doctorId;
}

string Appointment::getDate() const {

    return appointmentDate;
}

string Appointment::getTime() const {

    return appointmentTime;
}

void Appointment::cancelAppointment() {

    status = "Cancelled";
}

void Appointment::saveToFile(ofstream &out) {

    out << appointmentId << endl;

    out << patientId << endl;

    out << doctorId << endl;

    out << appointmentDate << endl;

    out << appointmentTime << endl;

    out << status << endl;
}

void Appointment::loadFromFile(ifstream &in) {

    in >> appointmentId;

    in >> patientId;

    in >> doctorId;

    in.ignore();

    getline(in, appointmentDate);

    getline(in, appointmentTime);

    getline(in, status);
}
