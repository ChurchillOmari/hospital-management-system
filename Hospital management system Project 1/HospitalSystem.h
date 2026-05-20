#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include <vector>
#include <fstream>
#include <queue>

#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "Medicine.h"
#include "Bill.h"
#include "Room.h"

class HospitalSystem {

private:

    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    queue<int> waitingQueue;
    priority_queue<int> emergencyQueue;
    vector<Medicine> medicines;
    vector<Bill> bills;
    vector<Room> rooms;


public:
    HospitalSystem();

    bool login();

    void addPatient();
    void displayPatients();
    void searchPatient();
    void deletePatient();
    void updatePatient();
    bool patientExists(int id);

    void addDoctor();
    void displayDoctors();
    void searchDoctor();
    void deleteDoctor();
    void updateDoctor();
    bool doctorExists(int id);

   // APPOINTMENTS


    void bookAppointment();

    void displayAppointments();

    void cancelAppointment();

    bool appointmentExists(int id);

    void saveAppointments();

    void loadAppointments();

    //queues

    void addToWaitingQueue();

    void serveNextPatient();

    void displayWaitingQueue();

    void addEmergencyPatient();

    void serveEmergencyPatient();

    void displayEmergencyQueue();

    //Medicine And Phamacy

    void addMedicine();

    void displayMedicines();

    void searchMedicine();

    void restockMedicine();

    void dispenseMedicine();

    bool medicineExists(int id);

    void saveMedicines();

    void loadMedicines();

    //Bill handling
    void generatePatientBill();

    void displayBills();

    void searchBill();

    void payBill();

    bool billExists(int id);

    void saveBills();

    void loadBills();

    //ROOM HANDLING
    void addRoom();

    void displayRooms();

    void admitPatientToRoom();

    void dischargeRoom();

    bool roomExists(int roomNumber);

    void saveRooms();

    void loadRooms();


     // FILE HANDLING
    void savePatients();

    void loadPatients();

    void saveDoctors();

    void loadDoctors();

    void menu();
};

#endif
