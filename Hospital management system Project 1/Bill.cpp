#include "Bill.h"

Bill::Bill() {

    billId = 0;

    patientId = 0;

    doctorFee = 0;

    medicineCost = 0;

    roomCharges = 0;

    totalAmount = 0;

    paymentStatus = "Unpaid";
}

void Bill::generateBill() {

    cout << "\n===== GENERATE BILL =====\n";

    cout << "Enter Bill ID: ";
    cin >> billId;

    cout << "Enter Patient ID: ";
    cin >> patientId;

    cout << "Enter Doctor Fee: ";
    cin >> doctorFee;

    cout << "Enter Medicine Cost: ";
    cin >> medicineCost;

    cout << "Enter Room Charges: ";
    cin >> roomCharges;

    totalAmount = calculateTotal();

    paymentStatus = "Unpaid";
}

double Bill::calculateTotal() {

    return doctorFee
           + medicineCost
           + roomCharges;
}

void Bill::displayBill() const {

    cout << "\n=========================\n";

    cout << "Bill ID         : "
         << billId << endl;

    cout << "Patient ID      : "
         << patientId << endl;

    cout << "Doctor Fee      : KES "
         << doctorFee << endl;

    cout << "Medicine Cost   : KES "
         << medicineCost << endl;

    cout << "Room Charges    : KES "
         << roomCharges << endl;

    cout << "Total Amount    : KES "
         << totalAmount << endl;

    cout << "Payment Status  : "
         << paymentStatus << endl;
}

int Bill::getBillId() const {

    return billId;
}

int Bill::getPatientId() const {

    return patientId;
}

void Bill::markAsPaid() {

    paymentStatus = "Paid";
}

string Bill::getPaymentStatus() const {

    return paymentStatus;
}

void Bill::saveToFile(ofstream &out) {

    out << billId << endl;

    out << patientId << endl;

    out << doctorFee << endl;

    out << medicineCost << endl;

    out << roomCharges << endl;

    out << totalAmount << endl;

    out << paymentStatus << endl;
}

void Bill::loadFromFile(ifstream &in) {

    in >> billId;

    in >> patientId;

    in >> doctorFee;

    in >> medicineCost;

    in >> roomCharges;

    in >> totalAmount;

    in.ignore();

    getline(in, paymentStatus);
}
