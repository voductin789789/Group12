#include "../headers/ui_helper.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void showMainMenu() {
    cout << "\n======================================" << endl;
    cout << "   WEBSITE CHIA SE CONG THUC NAU AN   " << endl;
    cout << "======================================" << endl;
    cout << "1. Tim kiem cong thuc" << endl;
    cout << "2. Xem theo danh muc" << endl;
    cout << "3. Dang nhap / Dang ky" << endl;
    cout << "4. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void drawHeader(string title) {
    cout << "\n=== " << title << " ===" << endl;
}

vector<string> splitString(string line, char delimiter) {
    vector<string> result;
    stringstream ss(line);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

string joinString(vector<string> fields, char delimiter) {
    string result;
    for (int i = 0; i < fields.size(); i++) {
        if (i > 0) result += delimiter;
        result += fields[i];
    }
    return result;
}