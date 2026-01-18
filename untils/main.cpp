#include <iostream>
#include <string>
#include "../headers/auth.h"
#include "../headers/recipe.h"
#include "../headers/category.h"
#include "../headers/interaction.h"
#include "../headers/ui_helper.h"

using namespace std;

int main() {
    Account currentUser;
    Recipe recipeManager;
    Category categoryManager;
    Interaction interactionManager;
    
    bool isRunning = true;
    int choice;

    while (isRunning) {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1: { // Tìm kiếm công thức
                string keyword;
                cout << "Nhap ten mon an hoac nguyen lieu: ";
                cin.ignore();
                getline(cin, keyword);
                recipeManager.searchRecipe(keyword);
                break;
            }
            case 2: { // Xem theo danh mục
                categoryManager.listAllCategories();
                break;
            }
            case 3: { // Đăng nhập / Đăng ký
                string u, p;
                cout << "Username: "; cin >> u;
                cout << "Password: "; cin >> p;
                
                if (currentUser.login(u, p)) {
                    cout << "Chao mung " << currentUser.getUsername() << " [" << currentUser.getRole() << "] quay tro lai!" << endl;
                } else {
                    cout << "Sai tai khoan hoac mat khau!" << endl;
                }
                break;
            }
            case 4: { // Thoát hệ thống
                cout << "Cam on ban da su dung Website Chia se Cong thuc Nau an!" << endl;
                isRunning = false;
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }

    return 0;
}