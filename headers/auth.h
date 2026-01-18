#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Account {
private:
    string username;
    string role;

public:
    bool login(string user, string pass);
    void registerAccount(string user, string pass, string mail);
    void resetPassword(string mail);
    string getUsername() const { return username; }
    string getRole() const { return role; }
};

#endif