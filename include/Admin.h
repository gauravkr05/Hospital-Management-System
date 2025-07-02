#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "hospital.h"
#include <string>
#include <iostream>

class Admin : public User {
private:
    std::string password;

public:
    Admin(const std::string& name, const std::string& password, const std::string& id = "");

    // Core Admin Operations
    void add_patient();
    void remove_patient();
    void add_doctor();
    void remove_doctor();

    // Appointment and Assignment
    void book_appointment();
    void assign_doctor();

    // Viewing Information
    void view_doctor_schedule();
    void view_treatment_records();
    void record_billing();

    // Admin Credentials
    void update_password();

    // Overrides
    void displayInfo() const override;
    std::string getRole() const override;

    // Menu UI
    void print_menu();
    void login_page();
};

#endif
