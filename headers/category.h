#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Category {
private:
    int categoryID;
    string categoryName;

public:
    void listAllCategories();
    void addCategory(string name); // Quản trị viên quản lý danh mục
    void deleteCategory(int id);
};

#endif