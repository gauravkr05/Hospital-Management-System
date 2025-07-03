#include "../include/patient.h"
using namespace std;

Patient::Patient(const string& id, const string& name, int age)
    : id(id), name(name), age(age) {}

string Patient::get_id() const { return id; }
string Patient::get_name() const { return name; }
int Patient::get_age() const { return age; }
void Patient::set_name(const string& new_name) { name = new_name; }
void Patient::set_age(int new_age) { age = new_age; }
