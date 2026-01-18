#include "../headers/category.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

const string PATH_CATEGORIES = "data/categories.txt";

void Category::listAllCategories() {
    ifstream in(PATH_CATEGORIES);
    if (!in) {
        cout << "Khong the mo file danh muc!" << endl;
        return;
    }
    string line;
    cout << "\n--- DANH SACH DANH MUC ---" << endl;
    while (getline(in, line)) {
        stringstream ss(line);
        string cID, cName;
        getline(ss, cID, '|');
        getline(ss, cName, '|');
        cout << "[" << cID << "] " << cName << endl;
    }
    in.close();
}

void Category::addCategory(string name) {
    ofstream out(PATH_CATEGORIES, ios::app);
    if (!out) {
        cout << "Loi: Khong the ghi danh muc!" << endl;
        return;
    }
    out << "0|" << name << endl;
    out.close();
    cout << "✅ Da them danh muc: " << name << endl;
}

void Category::deleteCategory(int id) {
    cout << "Xoa danh muc (chua implement)" << endl;
}