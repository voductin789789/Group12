#include "../headers/auth.h"
#include "../headers/file_manager.h"
#include <algorithm>

using namespace std;

User Account::login(const string& username, const string& password) {
    User user;
    vector<string> lines = FileManager::readLines(FileManager::ACCOUNTS_FILE);
    
    for (const string& line : lines) {
        vector<string> fields = FileManager::splitLine(line);
        
        if (fields.size() >= 5) {
            if (fields[1] == username && fields[2] == password) {
                user.setId(stoi(fields[0]));
                user.setUsername(fields[1]);
                user.setEmail(fields[3]);
                user.setRole(fields[4]);
                user.setAuthenticated(true);
                return user;
            }
        }
    }
    
    // Không tìm thấy → trả về user không xác thực
    return user;
}

bool Account::registerAccount(const string& username, const string& password, const string& email) {
    // Kiểm tra username đã tồn tại
    if (userExists(username)) {
        cerr << "Loi: Tai khoan '" << username << "' da ton tai!" << endl;
        return false;
    }
    
    // Lấy ID mới
    vector<string> lines = FileManager::readLines(FileManager::ACCOUNTS_FILE);
    int newId = lines.size() + 1;  // ID đơn giản
    
    // Tạo dòng dữ liệu
    vector<string> fields = {
        to_string(newId),
        username,
        password,
        email,
        "MEMBER"
    };
    string newLine = FileManager::joinFields(fields);
    
    // Ghi vào file
    bool success = FileManager::appendLine(FileManager::ACCOUNTS_FILE, newLine);
    if (success) {
        cout << "Dang ky thanh cong tai khoan: " << username << endl;
    }
    
    return success;
}

bool Account::userExists(const string& username) {
    vector<string> lines = FileManager::readLines(FileManager::ACCOUNTS_FILE);
    
    for (const string& line : lines) {
        vector<string> fields = FileManager::splitLine(line);
        if (fields.size() >= 2 && fields[1] == username) {
            return true;
        }
    }
    
    return false;
}

bool Account::resetPassword(const string& email, const string& newPassword) {
    vector<string> lines = FileManager::readLines(FileManager::ACCOUNTS_FILE);
    bool found = false;
    
    for (string& line : lines) {
        vector<string> fields = FileManager::splitLine(line);
        
        if (fields.size() >= 4 && fields[3] == email) {
            fields[2] = newPassword;  // Cập nhật mật khẩu
            line = FileManager::joinFields(fields);
            found = true;
            break;
        }
    }
    
    if (found) {
        FileManager::writeLines(FileManager::ACCOUNTS_FILE, lines);
        cout << "Mat khau da duoc cap nhat cho email: " << email << endl;
        return true;
    }
    
    cerr << "Loi: Khong tim thay email!" << endl;
    return false;
}

User Account::getUserById(int id) {
    User user;
    vector<string> lines = FileManager::readLines(FileManager::ACCOUNTS_FILE);
    
    for (const string& line : lines) {
        vector<string> fields = FileManager::splitLine(line);
        
        if (fields.size() >= 5 && stoi(fields[0]) == id) {
            user.setId(id);
            user.setUsername(fields[1]);
            user.setEmail(fields[3]);
            user.setRole(fields[4]);
            user.setAuthenticated(true);
            return user;
        }
    }
    
    return user;  // Trả về user rỗng nếu không tìm thấy
}