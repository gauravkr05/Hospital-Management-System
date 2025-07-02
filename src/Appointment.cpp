#include "../include/appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment(const string& appointment_id,
                         const string& patient_id,
                         const string& date,
                         const string& time)
    : appointment_id(appointment_id),
      patient_id(patient_id),
      date(date),
      time(time),
      isAssigned(false) {}

string Appointment::getAppointmentID() const {
    return appointment_id;
}

string Appointment::getPatientID() const {
    return patient_id;
}

string Appointment::getDoctorID() const {
    return doctor_id;
}

string Appointment::getDate() const {
    return date;
}

string Appointment::getTime() const {
    return time;
}

bool Appointment::assigned() const {
    return isAssigned;
}

void Appointment::assignDoctor(const string& doctor_id) {
    this->doctor_id = doctor_id;
    isAssigned = true;
}

void Appointment::displayAppointment() const {
    cout << "\n----- Appointment Details -----\n";
    cout << "Appointment ID: " << appointment_id << endl;
    cout << "Patient ID    : " << patient_id << endl;
    cout << "Date          : " << date << endl;
    cout << "Time          : " << time << endl;
    if (isAssigned)
        cout << "Doctor ID     : " << doctor_id << endl;
    else
        cout << "Doctor        : Not Assigned Yet" << endl;
    cout << "-------------------------------\n";
}

