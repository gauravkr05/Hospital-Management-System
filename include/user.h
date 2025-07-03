// include/User.h
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string user_id;
    string name;

public:
    User(const string& id, const string& name);
    virtual ~User() = default;
    virtual void displayInfo() const = 0;
    virtual string getRole() const = 0;
};

#endif
