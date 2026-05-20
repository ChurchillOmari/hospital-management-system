#include "Hospital.h"
#include <algorithm>
using namespace std;

Hospital::~Hospital() {
    for (auto p : allPatients) delete p;
}

void Hospital::addNewPatient(int id, string name, int age, string disease, string contact) {
    Patient* newPatient = new Patient(id, name, age, disease, contact);
    allPatients.push_back(newPatient);
    checkInQueue.push(newPatient);
    historyStack.push(newPatient);
    cout << "Patient " << name << " added successfully.\n";
}

void Hospital::processNextPatient() {
    if (checkInQueue.empty()) {
        cout << "No patients in the waiting queue.\n";
        return;
    }
    Patient* p = checkInQueue.front();
    cout << "Now treating: " << p->getName() << "\n";
    checkInQueue.pop();
}

void Hospital::sortPatientsByName() {
    sort(allPatients.begin(), allPatients.end(), [](Patient* a, Patient* b) {
        return a->getName() < b->getName();
    });
    cout << "Patients sorted by name.\n";
}

void Hospital::showAllPatients() {
    if (allPatients.empty()) {
        cout << "No patient records found.\n";
        return;
    }
    for (const auto& p : allPatients) {
        p->displayDetails();
    }
}
