#include "../include/Admin.h"
#include "../include/hospital.h"
#include "../include/helper_functions.h"
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
    if (!HelperFunctions::isValidNumber(ageStr)) {
        cout << "Invalid age format!\n"; return;
    }
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
    string pid, date, time;
    cout << "Enter patient ID: "; getline(cin, pid);
    cout << "Enter appointment date (DD/MM/YYYY): "; getline(cin, date);
    cout << "Enter time (e.g., 10:30AM): "; getline(cin, time);
    Hospital::getInstance().book_appointment(pid, date, time);
}

void Admin::assign_doctor() {
    string app_id, did;
    cout << "Enter appointment ID: "; getline(cin, app_id);
    cout << "Enter doctor ID to assign: "; getline(cin, did);
    Hospital::getInstance().assign_doctor(app_id, did);
}

void Admin::view_doctor_schedule() {
    string did;
    cout << "Enter doctor ID: "; getline(cin, did);
    Hospital::getInstance().view_doctor_schedule(did);
}

void Admin::view_treatment_records() {
    Hospital::getInstance().view_all_treatments();
}

void Admin::record_billing() {
    string pid, amountStr;
    cout << "Enter patient ID: "; getline(cin, pid);
    cout << "Enter amount: "; getline(cin, amountStr);
    if (!HelperFunctions::isValidNumber(amountStr)) {
        cout << "Invalid amount!\n"; return;
    }
    double amt = stod(amountStr);
    Hospital::getInstance().add_billing(pid, amt);
}

void Admin::update_password() {
    string pwd, cnf;
    cout << "Enter new password: "; getline(cin, pwd);
    cout << "Confirm new password: "; getline(cin, cnf);
    if (pwd != cnf) {
        cout << "Passwords do not match!\n";
    } else {
        password = pwd;
        cout << "Password updated successfully.\n";
    }
}

void Admin::print_menu() {
    cout << "\n================= ADMIN DASHBOARD =================\n";
    cout << "1. Add Patient\n2. Remove Patient\n3. Add Doctor\n4. Remove Doctor\n";
    cout << "5. Book Appointment\n6. Assign Doctor\n7. View Doctor Schedule\n";
    cout << "8. View Treatment Records\n9. Record Billing\n10. Update Password\n11. Logout\n";
    cout << "Enter your choice: ";
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
        else if (choice == "11") {
            cout << "Logged out successfully.\n"; break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
}