#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

// Đại diện cho một user đã đăng nhập
class User {
private:
    int id;
    string username;
    string email;
    string role;
    bool isAuthenticated;

public:
    User();
    
    // Getters
    int getId() const { return id; }
    string getUsername() const { return username; }
    string getEmail() const { return email; }
    string getRole() const { return role; }
    bool isLoggedIn() const { return isAuthenticated; }
    
    // Setters
    void setId(int userId) { id = userId; }
    void setUsername(const string& uname) { username = uname; }
    void setEmail(const string& mail) { email = mail; }
    void setRole(const string& r) { role = r; }
    void setAuthenticated(bool auth) { isAuthenticated = auth; }
    
    // Kiểm tra quyền
    bool isAdmin() const { return role == "ADMIN"; }
    bool isMember() const { return role == "MEMBER"; }
    
    // Reset thông tin
    void logout();
};

#endif
