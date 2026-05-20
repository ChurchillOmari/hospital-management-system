#include "Patient.h"

Patient::Patient() {
    admitted = false;
}

void Patient::inputPatient() {

    cout << "\n===== ADD PATIENT =====\n";

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

    cout << "Enter Disease: ";
    getline(cin, disease);

    cout << "Enter Blood Group: ";
    getline(cin, bloodGroup);

    admitted = true;

    cout << "\nPatient Added Successfully!\n";
}

void Patient::display() const {

    cout << "\n=========================\n";
    cout << "Patient ID: " << id << endl;
    cout << "Name      : " << name << endl;
    cout << "Age       : " << age << endl;
    cout << "Gender    : " << gender << endl;
    cout << "Phone     : " << phone << endl;
    cout << "Disease   : " << disease << endl;
    cout << "BloodGrp  : " << bloodGroup << endl;
    cout << "Status    : "
         << (admitted ? "Admitted" : "Discharged")
         << endl;
}

bool Patient::isAdmitted() const {
    return admitted;
}

void Patient::discharge() {
    admitted = false;
}void Patient::saveToFile(ofstream &out) {

    out << id << endl;
    out << name << endl;
    out << age << endl;
    out << gender << endl;
    out << phone << endl;
    out << disease << endl;
    out << bloodGroup << endl;
    out << admitted << endl;
}

void Patient::loadFromFile(ifstream &in) {

    in >> id;

    in.ignore();

    getline(in, name);

    in >> age;

    in.ignore();

    getline(in, gender);

    getline(in, phone);

    getline(in, disease);

    getline(in, bloodGroup);

    in >> admitted;

    in.ignore();
}
void Patient::updatePatient() {

    cin.ignore();

    cout << "\n===== UPDATE PATIENT =====\n";

    cout << "Enter New Name: ";
    getline(cin, name);

    cout << "Enter New Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter New Gender: ";
    getline(cin, gender);

    cout << "Enter New Phone: ";
    getline(cin, phone);

    cout << "Enter New Disease: ";
    getline(cin, disease);

    cout << "Enter New Blood Group: ";
    getline(cin, bloodGroup);

    cout << "\nPatient Updated Successfully!\n";
}
