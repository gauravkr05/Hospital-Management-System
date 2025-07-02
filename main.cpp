#include "include/Admin.h"
#include "include/helper_functions.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "===============================\n";
    cout << "  Offline Hospital Management\n";
    cout << "===============================\n";

    string username, password;
    
    // Dummy login (can be replaced with file-based or secure system later)
    cout << "Enter admin username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    // Simple authentication
    if (username == "admin" && password == "admin123") {
        Admin admin(username, password, "A001");
        admin.login_page();
    } else {
        cout << "Invalid credentials! Exiting...\n";
    }

    cout << "Thank you for using the system.\n";
    return 0;
}

