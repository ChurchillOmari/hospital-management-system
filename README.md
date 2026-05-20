# Hospital Management System

A comprehensive, modular Hospital Management System (HMS) developed using C++ and Object-Oriented Programming (OOP) principles. This system is designed to automate and streamline core hospital operations, improving efficiency and reducing reliance on manual paperwork.

## Table of Contents
- [About the Project](#about-the-project)
- [Key Features](#key-features)
- [System Architecture](#system-architecture)
- [Technical Stack](#technical-stack)
- [Project Structure](#project-structure)
- [Future Improvements](#future-improvements)

## About the Project
The Hospital Management System automates hospital workflows, including patient and doctor management, appointment scheduling, queue handling, pharmacy inventory, billing, and room allocation. It utilizes persistent file storage to ensure data availability across sessions.

## Key Features
- **Authentication**: Secure administrator login.
- **Patient & Doctor Management**: Add, search, and manage records.
- **Appointment Scheduling**: Book, manage, and cancel appointments.
- **Queue System**: Efficient management of waiting lines and emergency queues.
- **Inventory & Billing**: Pharmacy medicine management and automated bill generation.
- **Room Allocation**: Monitor hospital room occupancy.

## System Architecture
The system employs a modular, multi-file architecture where specialized modules interact with a centralized `HospitalSystem` controller, enhancing maintainability and scalability.

## Technical Stack
- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Data Structures**: Vectors (dynamic records), Queues (FIFO logic)
- **Storage**: Persistent file handling (Text Files: .txt)

## Project Structure
```text
HospitalManagementSystem/
├── main.cpp
├── HospitalSystem.h / .cpp
├── Patient.h / .cpp
├── Doctor.h / .cpp
├── Appointment.h / .cpp
├── Medicine.h / .cpp
├── Bill.h / .cpp
├── Room.h / .cpp
└── Database/
    ├── patients.txt
    ├── doctors.txt
    ├── appointments.txt
    ├── medicines.txt
    ├── bills.txt
    └── rooms.txt
