#include "HospitalSystem.h"


// CONSTRUCTOR

HospitalSystem::HospitalSystem() {

    loadPatients();

    loadDoctors();

    loadAppointments();

    loadMedicines();

    loadBills();

    loadRooms();
}

// LOGIN


bool HospitalSystem::login() {

    string username;
    string password;

    cout << "\n===== LOGIN =====\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    return (username == "admin"
         && password == "1234");
}
bool HospitalSystem::patientExists(int id) {

    for (auto &p : patients) {

        if (p.getId() == id) {

            return true;
        }
    }

    return false;
}
// ADD PATIENT
void HospitalSystem::addPatient() {

    Patient p;

    p.inputPatient();

      if (patientExists(p.getId())) {

        cout << "\nPatient ID already exists!\n";

        return;
    }

    patients.push_back(p);

    savePatients();
    cout << "\nPatient Saved Successfully!\n";
}

// DISPLAY PATIENTS
void HospitalSystem::displayPatients() {

    if (patients.empty()) {

        cout << "\nNo Patients Found.\n";

        return;
    }

    for (const auto &p : patients) {
        p.display();
    }
}

//SEARCHPATIENT
void HospitalSystem::searchPatient() {

    int id;

    cout << "\nEnter Patient ID: ";

    cin >> id;

    for (auto &p : patients) {

        if (p.getId() == id) {

            cout << "\nPatient Found:\n";

            p.display();

            return;
        }
    }

    cout << "\nPatient Not Found.\n";
}


//UPDATE PATIENT

void HospitalSystem::updatePatient() {

    int id;

    cout << "\nEnter Patient ID to Update: ";

    cin >> id;

    for (auto &p : patients) {

        if (p.getId() == id) {

            p.updatePatient();

            savePatients();

            return;
        }
    }

    cout << "\nPatient Not Found.\n";
}
//DELETE PATIENT
void HospitalSystem::deletePatient() {

    int id;

    cout << "\nEnter Patient ID to Delete: ";

    cin >> id;

    for (auto it = patients.begin();
         it != patients.end();
         ++it) {

        if (it->getId() == id) {

            patients.erase(it);

            savePatients();

            cout << "\nPatient Deleted Successfully.\n";

            return;
        }
    }

    cout << "\nPatient Not Found.\n";
}
bool HospitalSystem::doctorExists(int id) {

    for (auto &d : doctors) {

        if (d.getId() == id) {

            return true;
        }
    }

    return false;
}



// ADD DOCTOR
void HospitalSystem::addDoctor() {

    Doctor d;

    d.inputDoctor();
     if (doctorExists(d.getId())) {

        cout << "\nDoctor ID already exists!\n";

        return;
    }

    doctors.push_back(d);

    saveDoctors();
    cout << "\nDoctor Saved Successfully!\n";
}

// DISPLAY DOCTORS
void HospitalSystem::displayDoctors() {

    if (doctors.empty()) {

        cout << "\nNo Doctors Found.\n";

        return;
    }

    for (const auto &d : doctors) {
        d.display();
    }
}

//SEARCH DOCTOR
void HospitalSystem::searchDoctor() {

    int id;

    cout << "\nEnter Doctor ID: ";

    cin >> id;

    for (auto &d : doctors) {

        if (d.getId() == id) {

            cout << "\nDoctor Found:\n";

            d.display();

            return;
        }
    }

    cout << "\nDoctor Not Found.\n";
}
//UPDATE DOCTORS
void HospitalSystem::updateDoctor() {

    int id;

    cout << "\nEnter Doctor ID to Update: ";

    cin >> id;

    for (auto &d : doctors) {

        if (d.getId() == id) {

            d.updateDoctor();

            saveDoctors();

            return;
        }
    }

    cout << "\nDoctor Not Found.\n";
}
//DELETE DOCTORS
void HospitalSystem::deleteDoctor() {

    int id;

    cout << "\nEnter Doctor ID to Delete: ";

    cin >> id;

    for (auto it = doctors.begin();
         it != doctors.end();
         ++it) {

        if (it->getId() == id) {

            doctors.erase(it);

            saveDoctors();

            cout << "\nDoctor Deleted Successfully.\n";

            return;
        }
    }

    cout << "\nDoctor Not Found.\n";
}

// SAVE PATIENTS


void HospitalSystem::savePatients() {

    cout << "\nSaving Patients...\n";

    ofstream out("patients.txt");

    out << patients.size() << endl;

    for (auto &p : patients) {

        p.saveToFile(out);
    }

    out.close();
}


// LOAD PATIENTS


void HospitalSystem::loadPatients() {

    ifstream in("patients.txt");

    if (!in) {

        return;
    }

    int size;

    in >> size;

    in.ignore();

    for (int i = 0; i < size; i++) {

        Patient p;

        p.loadFromFile(in);

        patients.push_back(p);
    }

    in.close();
}


// SAVE DOCTORS

void HospitalSystem::saveDoctors() {

    cout << "\nSaving Doctors...\n";

    ofstream out("doctors.txt");

    out << doctors.size() << endl;

    for (auto &d : doctors) {

        d.saveToFile(out);
    }

    out.close();
}


// LOAD DOCTORS


void HospitalSystem::loadDoctors() {

    ifstream in("doctors.txt");

    if (!in) {

        return;
    }

    int size;

    in >> size;

    in.ignore();

    for (int i = 0; i < size; i++) {

        Doctor d;

        d.loadFromFile(in);

        doctors.push_back(d);
    }

    in.close();
}
bool HospitalSystem::appointmentExists(int id) {

    for (auto &a : appointments) {

        if (a.getAppointmentId() == id) {

            return true;
        }
    }

    return false;
}
void HospitalSystem::bookAppointment() {

    Appointment a;

    a.inputAppointment();

    if (appointmentExists(
        a.getAppointmentId()
    )) {

        cout << "\nAppointment ID already exists!\n";

        return;
    }

    appointments.push_back(a);

    waitingQueue.push(a.getPatientId());

    saveAppointments();

    cout << "\nAppointment Booked Successfully!\n";
}
void HospitalSystem::displayAppointments() {
     cout << "\nAPPOINTMENTS: "
         << appointments.size()
         << endl;

    if (appointments.empty()) {

        cout << "\nNo Appointments Found.\n";

        return;
    }

    for (const auto &a : appointments) {

        a.displayAppointment();
    }
}

void HospitalSystem::cancelAppointment() {

    int id;

    cout << "\nEnter Appointment ID to Cancel: ";

    cin >> id;

    for (auto &a : appointments) {

        if (a.getAppointmentId() == id) {

            a.cancelAppointment();

            saveAppointments();

            cout << "\nAppointment Cancelled Successfully.\n";

            return;
        }
    }

    cout << "\nAppointment Not Found.\n";
}

void HospitalSystem::saveAppointments() {

    ofstream out("appointments.txt");

    out << appointments.size() << endl;

    for (auto &a : appointments) {

        a.saveToFile(out);
    }

    out.close();
}

void HospitalSystem::loadAppointments() {

    ifstream in("appointments.txt");

    if (!in) {

        return;
    }

    int size;

    in >> size;

    in.ignore();

    for (int i = 0; i < size; i++) {

        Appointment a;

        a.loadFromFile(in);

        appointments.push_back(a);
    }

    in.close();
}

void HospitalSystem::addToWaitingQueue() {

    int patientId;

    cout << "\nEnter Patient ID: ";

    cin >> patientId;

    waitingQueue.push(patientId);

    cout << "\nPatient Added To Waiting Queue.\n";
}
void HospitalSystem::serveNextPatient() {

    if (waitingQueue.empty()) {

        cout << "\nNo Patients In Queue.\n";

        return;
    }

    int patientId = waitingQueue.front();

    waitingQueue.pop();

    cout << "\nServing Patient ID: "
         << patientId << endl;
}

void HospitalSystem::displayWaitingQueue() {

    if (waitingQueue.empty()) {

        cout << "\nWaiting Queue Empty.\n";

        return;
    }

    queue<int> tempQueue = waitingQueue;

    cout << "\n===== WAITING QUEUE =====\n";

    while (!tempQueue.empty()) {

        cout << "Patient ID: "
             << tempQueue.front()
             << endl;

        tempQueue.pop();
    }
}

void HospitalSystem::addEmergencyPatient() {

    int patientId;

    cout << "\nEnter Emergency Patient ID: ";

    cin >> patientId;

    emergencyQueue.push(patientId);

    cout << "\nEmergency Patient Added.\n";
}

void HospitalSystem::serveEmergencyPatient() {

    if (emergencyQueue.empty()) {

        cout << "\nNo Emergency Patients.\n";

        return;
    }

    int patientId = emergencyQueue.top();

    emergencyQueue.pop();

    cout << "\nServing Emergency Patient ID: "
         << patientId << endl;
}

void HospitalSystem::displayEmergencyQueue() {

    if (emergencyQueue.empty()) {

        cout << "\nEmergency Queue Empty.\n";

        return;
    }

    priority_queue<int> tempQueue
        = emergencyQueue;

    cout << "\n===== EMERGENCY QUEUE =====\n";

    while (!tempQueue.empty()) {

        cout << "Emergency Patient ID: "
             << tempQueue.top()
             << endl;

        tempQueue.pop();
    }
}

 //Madicine Validation

 bool HospitalSystem::medicineExists(int id) {

    for (auto &m : medicines) {

        if (m.getMedicineId() == id) {

            return true;
        }
    }

    return false;
}

 void HospitalSystem::addMedicine() {

    Medicine m;

    m.inputMedicine();

    if (medicineExists(
        m.getMedicineId()
    )) {

        cout << "\nMedicine ID already exists!\n";

        return;
    }

    medicines.push_back(m);

    saveMedicines();

    cout << "\nMedicine Added Successfully!\n";
}

void HospitalSystem::displayMedicines() {
    cout << "Available Medicine: "
     << medicines.size()
     << endl;

    if (medicines.empty()) {

        cout << "\nNo Medicines Available.\n";

        return;
    }

    for (const auto &m : medicines) {

        m.displayMedicine();
    }
}

void HospitalSystem::searchMedicine() {

    int id;

    cout << "\nEnter Medicine ID: ";

    cin >> id;

    for (const auto &m : medicines) {

        if (m.getMedicineId() == id) {

            cout << "\nMedicine Found:\n";

            m.displayMedicine();

            return;
        }
    }

    cout << "\nMedicine Not Found.\n";
}

void HospitalSystem::restockMedicine() {

    int id, amount;

    cout << "\nEnter Medicine ID: ";

    cin >> id;

    for (auto &m : medicines) {

        if (m.getMedicineId() == id) {

            cout << "Enter Quantity To Add: ";

            cin >> amount;

            m.addStock(amount);

            saveMedicines();

            cout << "\nMedicine Restocked Successfully!\n";

            return;
        }
    }

    cout << "\nMedicine Not Found.\n";
}

void HospitalSystem::dispenseMedicine() {

    int id, amount;

    cout << "\nEnter Medicine ID: ";

    cin >> id;

    for (auto &m : medicines) {

        if (m.getMedicineId() == id) {

            cout << "Enter Quantity To Dispense: ";

            cin >> amount;

            if (m.dispenseMedicine(amount)) {

                saveMedicines();

                cout << "\nMedicine Dispensed Successfully!\n";

            } else {

                cout << "\nInsufficient Stock!\n";
            }

            return;
        }
    }

    cout << "\nMedicine Not Found.\n";
}

void HospitalSystem::saveMedicines() {

    ofstream out("medicines.txt");

    out << medicines.size() << endl;

    for (auto &m : medicines) {

        m.saveToFile(out);
    }

    out.close();
}


void HospitalSystem::loadMedicines() {

    ifstream in("medicines.txt");

    if (!in) {

        return;
    }

    int size;

    in >> size;

    in.ignore();

    for (int i = 0; i < size; i++) {

        Medicine m;

        m.loadFromFile(in);

        medicines.push_back(m);
    }

    in.close();
}

bool HospitalSystem::billExists(int id) {

    for (auto &b : bills) {

        if (b.getBillId() == id) {

            return true;
        }
    }

    return false;
}

void HospitalSystem::generatePatientBill() {

    Bill b;

    b.generateBill();

    if (billExists(
        b.getBillId()
    )) {

        cout << "\nBill ID already exists!\n";

        return;
    }

    bills.push_back(b);

    saveBills();

    cout << "\nBill Generated Successfully!\n";
}


void HospitalSystem::displayBills() {
    cout << "\BILLS: "
     << bills.size()
     << endl;

    if (bills.empty()) {

        cout << "\nNo Bills Available.\n";

        return;
    }

    for (const auto &b : bills) {

        b.displayBill();
    }
}

void HospitalSystem::searchBill() {

    int id;

    cout << "\nEnter Bill ID: ";

    cin >> id;

    for (const auto &b : bills) {

        if (b.getBillId() == id) {

            cout << "\nBill Found:\n";

            b.displayBill();

            return;
        }
    }

    cout << "\nBill Not Found.\n";
}


void HospitalSystem::payBill() {

    int id;

    cout << "\nEnter Bill ID: ";

    cin >> id;

    for (auto &b : bills) {

        if (b.getBillId() == id) {

            b.markAsPaid();

            saveBills();

            cout << "\nBill Paid Successfully!\n";

            return;
        }
    }

    cout << "\nBill Not Found.\n";
}

void HospitalSystem::saveBills() {

    ofstream out("bills.txt");

    out << bills.size() << endl;

    for (auto &b : bills) {

        b.saveToFile(out);
    }

    out.close();
}


void HospitalSystem::loadBills() {

    ifstream in("bills.txt");

    if (!in) {

        return;
    }

    int size;

    in >> size;

    in.ignore();

    for (int i = 0; i < size; i++) {

        Bill b;

        b.loadFromFile(in);

        bills.push_back(b);
    }

    in.close();
}

bool HospitalSystem::roomExists(int roomNumber) {

    for (auto &r : rooms) {

        if (r.getRoomNumber() == roomNumber) {

            return true;
        }
    }

    return false;
}

void HospitalSystem::addRoom() {

    Room r;

    r.addRoom();

    if (roomExists(
        r.getRoomNumber()
    )) {

        cout << "\nRoom already exists!\n";

        return;
    }

    rooms.push_back(r);

    saveRooms();

    cout << "\nRoom Added Successfully!\n";
}

void HospitalSystem::displayRooms() {
    cout << "\n ROOMS: "
     << rooms.size()
     << endl;

    if (rooms.empty()) {

        cout << "\nNo Rooms Available.\n";

        return;
    }

    for (const auto &r : rooms) {

        r.displayRoom();
    }
}

void HospitalSystem::admitPatientToRoom() {

    int roomNumber, patientId;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    cout << "Enter Patient ID: ";
    cin >> patientId;

    for (auto &r : rooms) {

        if (r.getRoomNumber() == roomNumber) {

            if (r.isOccupied()) {

                cout << "\nRoom Already Occupied!\n";

                return;
            }

            r.admitPatient(patientId);

            saveRooms();

            cout << "\nPatient Admitted Successfully!\n";

            return;
        }
    }

    cout << "\nRoom Not Found.\n";
}

void HospitalSystem::dischargeRoom() {

    int roomNumber;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    for (auto &r : rooms) {

        if (r.getRoomNumber() == roomNumber) {

            if (!r.isOccupied()) {

                cout << "\nRoom Already Empty.\n";

                return;
            }

            r.dischargePatient();

            saveRooms();

            cout << "\nRoom Discharged Successfully!\n";

            return;
        }
    }

    cout << "\nRoom Not Found.\n";
}

void HospitalSystem::saveRooms() {

    ofstream out("rooms.txt");

    out << rooms.size() << endl;

    for (auto &r : rooms) {

        r.saveToFile(out);
    }

    out.close();
}

void HospitalSystem::loadRooms() {

    ifstream in("rooms.txt");

    if (!in) {

        return;
    }

    int size;

    in >> size;

    in.ignore();

    for (int i = 0; i < size; i++) {

        Room r;

        r.loadFromFile(in);

        rooms.push_back(r);
    }

    in.close();
}


// MENU

void HospitalSystem::menu() {

    int choice;

    do {

        cout << "\n========== HOSPITAL MENU ==========\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Delete Patient\n";

        cout << "6. Add Doctor\n";
        cout << "7. Display Doctors\n";
        cout << "8. Search Doctor\n";
        cout << "9. Update Doctor\n";
        cout << "10. Delete Doctor\n";
        cout << "11. Book Appointment\n";
        cout << "12. Display Appointments\n";
        cout << "13. Cancel Appointment\n";
        cout << "15. Add Patient To Waiting Queue\n";
        cout << "16. Serve Next Patient\n";
        cout << "17. Display Waiting Queue\n";
        cout << "18. Add Emergency Patient\n";
        cout << "19. Serve Emergency Patient\n";
        cout << "20. Display Emergency Queue\n";
        cout << "21. Add Medicine\n";
        cout << "22. Display Medicines\n";
        cout << "23. Search Medicine\n";
        cout << "24. Restock Medicine\n";
        cout << "25. Dispense Medicine\n";
        cout << "26. Generate Bill\n";
        cout << "27. Display Bills\n";
        cout << "28. Search Bill\n";
        cout << "29. Pay Bill\n";
        cout << "30. Add Room\n";
        cout << "31. Display Rooms\n";
        cout << "32. Admit Patient To Room\n";
        cout << "33. Discharge Room\n";
        cout << "34. Exit\n";





        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

              case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                addDoctor();
                break;
             case 7:
                displayDoctors();
                break;

            case 8:
                searchDoctor();
                break;

            case 9:
                updateDoctor();
                break;

            case 10:
                deleteDoctor();
                break;

            case 11:
                bookAppointment();
                break;

            case 12:
                displayAppointments();
                break;

            case 13:
                cancelAppointment();
                break;

            case 14:
                cout << "\nExiting System...\n";
                break;
            case 15:
                addToWaitingQueue();
                break;

            case 16:
                serveNextPatient();
               break;

            case 17:
                displayWaitingQueue();
               break;

            case 18:
                 addEmergencyPatient();
               break;

            case 19:
                  serveEmergencyPatient();
               break;

            case 20:
                  displayEmergencyQueue();
               break;
            case 21:
                  addMedicine();
               break;

            case 22:
                   displayMedicines();
               break;

             case 23:
                  searchMedicine();
              break;

             case 24:
                  restockMedicine();
              break;

              case 25:
                  dispenseMedicine();
              break;
               case 26:
                  generatePatientBill();
              break;

                case 27:
                   displayBills();
              break;

                case 28:
                   searchBill();
               break;

                 case 29:
                   payBill();
               break;
                 case 30:
                   addRoom();
               break;

                 case 31:
                   displayRooms();
               break;

                 case 32:
                    admitPatientToRoom();
               break;

                 case 33:
                    dischargeRoom();
               break;

                 case 34:
                     cout << "\nExiting System...\n";
               break;

               default:
                     cout << "\nInvalid Choice.\n";
        }

    } while (choice != 34);
}
