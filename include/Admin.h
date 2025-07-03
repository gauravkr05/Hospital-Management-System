#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "hospital.h"
#include <string>

class Admin : public User {
private:
    std::string password;

public:
    Admin(const std::string& name, const std::string& pwd, const std::string& id);
    void displayInfo() const override;
    std::string getRole() const override;
    void login_page();

    void print_menu();
    void add_patient();
    void remove_patient();
    void add_doctor();
    void remove_doctor();
    void book_appointment();
    void assign_doctor();
    void view_doctor_schedule();
    void view_treatment_records();
    void record_billing();
    void update_password();
};

#endif
