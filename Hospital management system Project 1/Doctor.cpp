#include "Doctor.h"

Doctor::Doctor() {
    consultationFee = 0;
}

void Doctor::inputDoctor() {

    cout << "\n===== ADD DOCTOR =====\n";

    cout << "Enter ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter Specialization: ";
    getline(cin, specialization);

    cout << "Enter Consultation Fee: ";
    cin >> consultationFee;

    cout << "\nDoctor Added Successfully!\n";
}

void Doctor::display() const {

    cout << "\n=========================\n";
    cout << "Doctor ID     : " << id << endl;
    cout << "Name          : " << name << endl;
    cout << "Age           : " << age << endl;
    cout << "Gender        : " << gender << endl;
    cout << "Phone         : " << phone << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Consult Fee   : KES "
         << consultationFee << endl;
}void Doctor::saveToFile(ofstream &out) {

    out << id << endl;
    out << name << endl;
    out << age << endl;
    out << gender << endl;
    out << phone << endl;
    out << specialization << endl;
    out << consultationFee << endl;
}

void Doctor::loadFromFile(ifstream &in) {

    in >> id;

    in.ignore();

    getline(in, name);

    in >> age;

    in.ignore();

    getline(in, gender);

    getline(in, phone);

    getline(in, specialization);

    in >> consultationFee;

    in.ignore();
}void Doctor::updateDoctor() {

    cin.ignore();

    cout << "\n===== UPDATE DOCTOR =====\n";

    cout << "Enter New Name: ";
    getline(cin, name);

    cout << "Enter New Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter New Gender: ";
    getline(cin, gender);

    cout << "Enter New Phone: ";
    getline(cin, phone);

    cout << "Enter New Specialization: ";
    getline(cin, specialization);

    cout << "Enter New Consultation Fee: ";
    cin >> consultationFee;

    cout << "\nDoctor Updated Successfully!\n";
}
