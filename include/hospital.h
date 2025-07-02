
#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <map>
#include <vector>
#include <string>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
#include "billing.h"

class Hospital {
private:
    std::map<std::string, Patient> patients;
    std::map<std::string, Doctor> doctors;
    std::map<std::string, Appointment> appointments;
    std::map<std::string, Billing> billings;

    int patient_counter = 0;
    int doctor_counter = 0;
    int appointment_counter = 0;
    int billing_counter = 0;

    Hospital();

public:
    static Hospital& getInstance();

    // Patient management
    void add_patient(const std::string& name, int age);
    bool remove_patient(const std::string& id);

    // Doctor management
    void add_doctor(const std::string& name, const std::string& spec);
    bool remove_doctor(const std::string& id);

    // Appointment management
    void book_appointment(const std::string& patient_id, const std::string& date, const std::string& time);
    void assign_doctor(const std::string& appointment_id, const std::string& doctor_id);
    void view_doctor_schedule(const std::string& doctor_id) const;

    // Treatment and billing
    void view_all_treatments() const;
    void add_billing(const std::string& patient_id, double base_amount);
};

#endif