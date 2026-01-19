#ifndef AUTH_H
#define AUTH_H

#include <string>
#include "user.h"

using namespace std;

// Quản lý xác thực người dùng
class Account {
public:
    // Đăng nhập: trả về User nếu thành công, User không xác thực nếu thất bại
    User login(const string& username, const string& password);
    
    // Đăng ký tài khoản mới
    bool registerAccount(const string& username, const string& password, const string& email);
    
    // Kiểm tra tên người dùng đã tồn tại hay chưa
    bool userExists(const string& username);
    
    // Reset mật khẩu
    bool resetPassword(const string& email, const string& newPassword);
    
    // Lấy người dùng theo ID
    User getUserById(int id);
};

#endif