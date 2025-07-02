#include "../include/hospital.h"
#include "../include/helper_functions.h"
#include <iostream>

using namespace std;

Hospital::Hospital() {}

Hospital& Hospital::getInstance() {
    static Hospital instance;
    return instance;
}

void Hospital::add_patient(const string& name, int age) {
    string id = "P" + to_string(++patient_counter);
    patients[id] = Patient(name, age, id);
}

bool Hospital::remove_patient(const string& id) {
    return patients.erase(id);
}

void Hospital::add_doctor(const string& name, const string& spec) {
    string id = "D" + to_string(++doctor_counter);
    doctors[id] = Doctor(name, spec, id);
}

bool Hospital::remove_doctor(const string& id) {
    return doctors.erase(id);
}

void Hospital::book_appointment(const string& patient_id, const string& date, const string& time) {
    if (patients.find(patient_id) == patients.end()) {
        cout << "Patient not found!\n";
        return;
    }
    string id = "A" + to_string(++appointment_counter);
    appointments[id] = Appointment(id, patient_id, date, time);
    cout << "Appointment booked successfully. ID: " << id << "\n";
}

void Hospital::assign_doctor(const string& appointment_id, const string& doctor_id) {
    if (appointments.find(appointment_id) == appointments.end()) {
        cout << "Appointment not found!\n";
        return;
    }
    if (doctors.find(doctor_id) == doctors.end()) {
        cout << "Doctor not found!\n";
        return;
    }
    appointments[appointment_id].assignDoctor(doctor_id);
    cout << "Doctor assigned successfully.\n";
}

void Hospital::view_doctor_schedule(const string& doctor_id) const {
    if (doctors.find(doctor_id) == doctors.end()) {
        cout << "Doctor not found!\n";
        return;
    }
    cout << "\n--- Schedule for Doctor ID: " << doctor_id << " ---\n";
    for (const auto& pair : appointments) {
    if (pair.second.getDoctorID() == doctor_id) {
        pair.second.displayAppointment();
    }
}
}

void Hospital::view_all_treatments() const {
    cout << "\n--- All Treatment Records ---\n";
     for (const auto& pair : patients) {
       pair.second.displayInfo();
       cout << endl;
   }
}

void Hospital::add_billing(const string& patient_id, double base_amount) {
    if (patients.find(patient_id) == patients.end()) {
        cout << "Patient not found!\n";
        return;
    }
    string id = "B" + to_string(++billing_counter);
    string last_appointment = "";
    for (auto it = appointments.rbegin(); it != appointments.rend(); ++it) {
        if (it->second.getPatientID() == patient_id) {
            last_appointment = it->first;
            break;
        }
    }
    if (last_appointment.empty()) {
        cout << "No appointment found for billing.\n";
        return;
    }
    billings[id] = Billing(id, patient_id, last_appointment, base_amount);
    billings[id].displayBill();
}
