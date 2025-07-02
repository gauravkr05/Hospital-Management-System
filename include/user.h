#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string user_id;
    std::string name;

public:
    User(const std::string& id, const std::string& name);

    virtual void displayInfo() const = 0;
    virtual std::string getRole() const = 0;

    std::string getID() const;
    std::string getName() const;
    void setName(const std::string& newName);
};

#endif