#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
using namespace std;

class Doctor {
private:
    string id;
    string name;
    string specialization;

public:
    Doctor() = default;
    Doctor(const string& id, const string& name, const string& specialization);
    string get_id() const;
    string get_name() const;
    string get_specialization() const;
    void set_name(const std::string& name);
    void set_specialization(const std::string& specialization);
};

#endif // DOCTOR_H