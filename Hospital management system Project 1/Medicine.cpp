#include "Medicine.h"

Medicine::Medicine() {

    medicineId = 0;

    medicineName = "";

    quantity = 0;

    price = 0.0;

    manufacturer = "";
}

void Medicine::inputMedicine() {

    cout << "\n===== ADD MEDICINE =====\n";

    cout << "Enter Medicine ID: ";
    cin >> medicineId;

    cin.ignore();

    cout << "Enter Medicine Name: ";
    getline(cin, medicineName);

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Price: ";
    cin >> price;

    cin.ignore();

    cout << "Enter Manufacturer: ";
    getline(cin, manufacturer);
}

void Medicine::displayMedicine() const {

    cout << "\n=========================\n";

    cout << "Medicine ID   : "
         << medicineId << endl;

    cout << "Medicine Name : "
         << medicineName << endl;

    cout << "Quantity      : "
         << quantity << endl;

    cout << "Price         : KES "
         << price << endl;

    cout << "Manufacturer  : "
         << manufacturer << endl;

    if (isLowStock()) {

        cout << "LOW STOCK ALERT!\n";
    }
}

int Medicine::getMedicineId() const {

    return medicineId;
}

string Medicine::getMedicineName() const {

    return medicineName;
}

int Medicine::getQuantity() const {

    return quantity;
}

void Medicine::addStock(int amount) {

    quantity += amount;
}

bool Medicine::dispenseMedicine(int amount) {

    if (amount > quantity) {

        return false;
    }

    quantity -= amount;

    return true;
}

bool Medicine::isLowStock() const {

    return quantity <= 10;
}

void Medicine::saveToFile(ofstream &out) {

    out << medicineId << endl;

    out << medicineName << endl;

    out << quantity << endl;

    out << price << endl;

    out << manufacturer << endl;
}

void Medicine::loadFromFile(ifstream &in) {

    in >> medicineId;

    in.ignore();

    getline(in, medicineName);

    in >> quantity;

    in >> price;

    in.ignore();

    getline(in, manufacturer);
}
