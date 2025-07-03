#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient {
private:
    string id;
    string name;
    int age;

public:
    Patient() = default;
    Patient(const std::string& id, const std::string& name, int age);
    string get_id() const;
    string get_name() const;
    int get_age() const;
    void set_name(const std::string& name);
    void set_age(int age);
};

#endif