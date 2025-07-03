#include "../include/Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(const string& name, const string& pwd, const string& id)
    : User(id, name), password(pwd) {}

void Admin::displayInfo() const {
    cout << "\n--- Admin Profile ---\n";
    cout << "ID   : " << user_id << "\n";
    cout << "Name : " << name << "\n";
}

string Admin::getRole() const {
    return "Admin";
}

void Admin::add_patient() {
    string name, ageStr;
    cout << "Enter patient name: "; getline(cin, name);
    cout << "Enter age: "; getline(cin, ageStr);
    int age = stoi(ageStr);
    Hospital::getInstance().add_patient(name, age);
    cout << "Patient added successfully.\n";
}

void Admin::remove_patient() {
    string pid;
    cout << "Enter patient ID to remove: "; getline(cin, pid);
    if (Hospital::getInstance().remove_patient(pid)) {
        cout << "Patient removed successfully.\n";
    } else {
        cout << "Patient not found.\n";
    }
}

void Admin::add_doctor() {
    string name, spec;
    cout << "Enter doctor name: "; getline(cin, name);
    cout << "Enter specialization: "; getline(cin, spec);
    Hospital::getInstance().add_doctor(name, spec);
    cout << "Doctor added successfully.\n";
}

void Admin::remove_doctor() {
    string did;
    cout << "Enter doctor ID to remove: "; getline(cin, did);
    if (Hospital::getInstance().remove_doctor(did)) {
        cout << "Doctor removed successfully.\n";
    } else {
        cout << "Doctor not found.\n";
    }
}

void Admin::book_appointment() {
    cout << "[Stub] Booking appointment...\n";
}

void Admin::assign_doctor() {
    cout << "[Stub] Assigning doctor...\n";
}

void Admin::view_doctor_schedule() {
    cout << "[Stub] Viewing doctor schedule...\n";
}

void Admin::view_treatment_records() {
    cout << "[Stub] Viewing all treatments...\n";
}

void Admin::record_billing() {
    cout << "[Stub] Recording billing...\n";
}

void Admin::update_password() {
    string pwd, cnf;
    cout << "Enter new password: "; getline(cin, pwd);
    cout << "Confirm new password: "; getline(cin, cnf);
    if (pwd == cnf) {
        password = pwd;
        cout << "Password updated.\n";
    } else {
        cout << "Passwords do not match.\n";
    }
}

void Admin::print_menu() {
    cout << "\n==== ADMIN MENU ====" << endl;
    cout << "1. Add Patient\n2. Remove Patient\n3. Add Doctor\n4. Remove Doctor\n";
    cout << "5. Book Appointment\n6. Assign Doctor\n7. View Schedule\n8. View Treatments\n";
    cout << "9. Record Billing\n10. Update Password\n11. Logout\n";
    cout << "Enter choice: ";
}

void Admin::login_page() {
    string choice;
    while (true) {
        print_menu();
        getline(cin, choice);
        if (choice == "1") add_patient();
        else if (choice == "2") remove_patient();
        else if (choice == "3") add_doctor();
        else if (choice == "4") remove_doctor();
        else if (choice == "5") book_appointment();
        else if (choice == "6") assign_doctor();
        else if (choice == "7") view_doctor_schedule();
        else if (choice == "8") view_treatment_records();
        else if (choice == "9") record_billing();
        else if (choice == "10") update_password();
        else if (choice == "11") break;
        else cout << "Invalid choice.\n";
    }
}