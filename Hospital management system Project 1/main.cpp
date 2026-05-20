#include "HospitalSystem.h"

int main() {

    cout << "===================================\n";
    cout << " HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "===================================\n";

    HospitalSystem system;

    if (system.login()) {

        cout << "\nLogin Successful!\n";

        system.menu();
    }
    else {

        cout << "\nInvalid Username or Password.\n";
    }

    return 0;
}
