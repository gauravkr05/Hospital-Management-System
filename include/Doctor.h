// DOCTOR.H
#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>
#include "user.h"

class Doctor : public User {
private:
    std::string specialization;

public:
    Doctor(const std::string& name, const std::string& specialization, const std::string& id = "");

    void viewAppointments() const;
    void treatPatient(const std::string& appointmentId);

    std::string getSpecialization() const;

    void displayInfo() const override;
    std::string getRole() const override;
};

#endif
