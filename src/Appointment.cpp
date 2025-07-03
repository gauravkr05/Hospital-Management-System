#include "../include/appointment.h"

Appointment::Appointment(const std::string& appointment_id,
                         const std::string& patient_id,
                         const std::string& doctor_id,
                         const std::string& date)
    : appointment_id(appointment_id), patient_id(patient_id), doctor_id(doctor_id), date(date) {}

std::string Appointment::get_appointment_id() const { return appointment_id; }
std::string Appointment::get_patient_id() const { return patient_id; }
std::string Appointment::get_doctor_id() const { return doctor_id; }
std::string Appointment::get_date() const { return date; }
