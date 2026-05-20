#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Medicine {

private:

    int medicineId;

    string medicineName;

    int quantity;

    double price;

    string manufacturer;

public:

    Medicine();

    void inputMedicine();

    void displayMedicine() const;

    int getMedicineId() const;

    string getMedicineName() const;

    int getQuantity() const;

    void addStock(int amount);

    bool dispenseMedicine(int amount);

    bool isLowStock() const;

    void saveToFile(ofstream &out);

    void loadFromFile(ifstream &in);
};

#endif
