#include "../headers/user.h"

using namespace std;

User::User() : id(0), username(""), email(""), role(""), isAuthenticated(false) {}

void User::logout() {
    id = 0;
    username = "";
    email = "";
    role = "";
    isAuthenticated = false;
}
