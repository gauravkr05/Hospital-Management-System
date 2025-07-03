#include "../include/doctor.h"
using namespace std;

Doctor::Doctor(const string& id, const string& name, const string& specialization)
    : id(id), name(name), specialization(specialization) {}

string Doctor::get_id() const { return id; }
string Doctor::get_name() const { return name; }
string Doctor::get_specialization() const { return specialization; }
void Doctor::set_name(const std::string& new_name) { name = new_name; }
void Doctor::set_specialization(const std::string& new_spec) { specialization = new_spec; }




