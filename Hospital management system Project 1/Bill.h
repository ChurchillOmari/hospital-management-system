#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bill {

private:

    int billId;

    int patientId;

    double doctorFee;

    double medicineCost;

    double roomCharges;

    double totalAmount;

    string paymentStatus;

public:

    Bill();

    void generateBill();

    void displayBill() const;

    int getBillId() const;

    int getPatientId() const;

    double calculateTotal();

    void markAsPaid();

    string getPaymentStatus() const;

    void saveToFile(ofstream &out);

    void loadFromFile(ifstream &in);
};

#endif
