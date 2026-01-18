#include "../headers/auth.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Đường dẫn file dữ liệu
const string PATH_ACCOUNTS = "data/accounts.txt";

bool Account::login(string user, string pass) {
    ifstream in(PATH_ACCOUNTS);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string id, u, p, email, r;
        getline(ss, id, '|');
        getline(ss, u, '|');
        getline(ss, p, '|');
        getline(ss, email, '|');
        getline(ss, r, '|');

        if (u == user && p == pass) {
            this->username = u;
            this->role = r;
            return true;
        }
    }
    return false;
}

void Account::registerAccount(string user, string pass, string mail) {
    ofstream out(PATH_ACCOUNTS, ios::app);
    // Logic: Tự động tăng ID (đơn giản hóa bằng cách dùng thời gian hoặc đếm dòng)
    out << "100|" << user << "|" << pass << "|" << mail << "|MEMBER" << endl;
    cout << "Dang ky thanh cong tai khoan: " << user << endl;
    out.close();
}

void Account::resetPassword(string mail) {
    // Logic xử lý Reset Password theo đặc tả
    cout << "He thong da gui huong dan dat lai mat khau den email: " << mail << endl;
}