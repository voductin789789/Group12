#include "../headers/menu_manager.h"
#include <iostream>
#include <limits>

using namespace std;

MenuManager::MenuManager() : isRunning(true) {}

void MenuManager::run() {
    while (isRunning) {
        if (currentUser.isLoggedIn()) {
            if (currentUser.isAdmin()) {
                showAdminMenu();
            } else {
                showUserMenu();
            }
        } else {
            showMainMenu();
        }
    }
}

void MenuManager::showMainMenu() {
    cout << "\n========== CHIA SE CONG THUC NAU AN ==========" << endl;
    cout << "1. Tim kiem cong thuc" << endl;
    cout << "2. Xem theo danh muc" << endl;
    cout << "3. Dang nhap / Dang ky" << endl;
    cout << "4. Thoat" << endl;
    cout << "Chon: ";
    
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
        case 1:
            handleSearch();
            break;
        case 2:
            handleViewRecipes();
            break;
        case 3:
            handleLogin();
            break;
        case 4:
            cout << "Cam on ban da su dung Website Chia se Cong thuc Nau an!" << endl;
            isRunning = false;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
    }
}

void MenuManager::showUserMenu() {
    cout << "\n========== MENU THANH VIEN ==========" << endl;
    cout << "Xin chao " << currentUser.getUsername() << "!" << endl;
    cout << "1. Tim kiem cong thuc" << endl;
    cout << "2. Xem danh sach cong thuc" << endl;
    cout << "3. Them cong thuc moi" << endl;
    cout << "4. Sua cong thuc" << endl;
    cout << "5. Xoa cong thuc" << endl;
    cout << "6. Dang xuat" << endl;
    cout << "7. Thoat" << endl;
    cout << "Chon: ";
    
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
        case 1:
            handleSearch();
            break;
        case 2:
            handleViewRecipes();
            break;
        case 3:
            handleAddRecipe();
            break;
        case 4:
            handleEditRecipe();
            break;
        case 5:
            handleDeleteRecipe();
            break;
        case 6:
            currentUser.logout();
            cout << "Dang xuat thanh cong!" << endl;
            break;
        case 7:
            cout << "Cam on ban da su dung Website Chia se Cong thuc Nau an!" << endl;
            isRunning = false;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
    }
}

void MenuManager::showAdminMenu() {
    cout << "\n========== MENU QUAN TRI VIEN ==========" << endl;
    cout << "Xin chao " << currentUser.getUsername() << " [ADMIN]!" << endl;
    cout << "1. Tim kiem cong thuc" << endl;
    cout << "2. Xem danh sach cong thuc" << endl;
    cout << "3. Them cong thuc" << endl;
    cout << "4. Sua cong thuc" << endl;
    cout << "5. Xoa cong thuc" << endl;
    cout << "6. Quan ly nguoi dung (chua implement)" << endl;
    cout << "7. Dang xuat" << endl;
    cout << "8. Thoat" << endl;
    cout << "Chon: ";
    
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
        case 1:
            handleSearch();
            break;
        case 2:
            handleViewRecipes();
            break;
        case 3:
            handleAddRecipe();
            break;
        case 4:
            handleEditRecipe();
            break;
        case 5:
            handleDeleteRecipe();
            break;
        case 6:
            cout << "Chuc nang nay se som duoc cap nhat!" << endl;
            break;
        case 7:
            currentUser.logout();
            cout << "Dang xuat thanh cong!" << endl;
            break;
        case 8:
            cout << "Cam on ban da su dung Website Chia se Cong thuc Nau an!" << endl;
            isRunning = false;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
    }
}

void MenuManager::handleSearch() {
    string keyword;
    cout << "Nhap tu khoa tim kiem: ";
    getline(cin, keyword);
    recipeManager.searchRecipe(keyword);
    pause();
}

void MenuManager::handleViewRecipes() {
    recipeManager.listAllRecipes();
    pause();
}

void MenuManager::handleAddRecipe() {
    RecipeData recipe;
    
    cout << "\n--- THEM CONG THUC MOI ---" << endl;
    cout << "Tieu de: ";
    getline(cin, recipe.title);
    
    cout << "Mo ta: ";
    getline(cin, recipe.description);
    
    cout << "Nguyen lieu: ";
    getline(cin, recipe.ingredients);
    
    cout << "Cach lam: ";
    getline(cin, recipe.instructions);
    
    cout << "Thoi gian nau (phut): ";
    cin >> recipe.cookingTime;
    cin.ignore();
    
    cout << "Muc do kho (EASY/MEDIUM/HARD): ";
    getline(cin, recipe.difficulty);
    
    cout << "ID danh muc: ";
    cin >> recipe.categoryId;
    cin.ignore();
    
    if (recipeManager.addRecipe(recipe, currentUser)) {
        cout << "Them cong thuc thanh cong!" << endl;
    } else {
        cout << "Loi: Khong the them cong thuc!" << endl;
    }
    
    pause();
}

void MenuManager::handleEditRecipe() {
    int recipeId;
    cout << "Nhap ID cong thuc can sua: ";
    cin >> recipeId;
    cin.ignore();
    
    RecipeData recipe = recipeManager.getRecipeById(recipeId);
    
    if (recipe.id == 0) {
        cout << "Khong tim thay cong thuc!" << endl;
        pause();
        return;
    }
    
    RecipeData newData = recipe;
    
    cout << "\nTieu de (" << recipe.title << "): ";
    getline(cin, newData.title);
    if (newData.title.empty()) newData.title = recipe.title;
    
    cout << "Mo ta (" << recipe.description << "): ";
    getline(cin, newData.description);
    if (newData.description.empty()) newData.description = recipe.description;
    
    if (recipeManager.editRecipe(recipeId, newData, currentUser)) {
        cout << "Sua cong thuc thanh cong!" << endl;
    } else {
        cout << "Loi: Khong the sua cong thuc!" << endl;
    }
    
    pause();
}

void MenuManager::handleDeleteRecipe() {
    int recipeId;
    cout << "Nhap ID cong thuc can xoa: ";
    cin >> recipeId;
    cin.ignore();
    
    if (recipeManager.deleteRecipe(recipeId, currentUser)) {
        cout << "Xoa cong thuc thanh cong!" << endl;
    } else {
        cout << "Loi: Khong the xoa cong thuc!" << endl;
    }
    
    pause();
}

void MenuManager::handleViewRecipeDetail(int recipeId) {
    RecipeData recipe = recipeManager.getRecipeById(recipeId);
    
    if (recipe.id == 0) {
        cout << "Khong tim thay cong thuc!" << endl;
        return;
    }
    
    cout << "\n========== CHI TIET CONG THUC ==========" << endl;
    cout << "ID: " << recipe.id << endl;
    cout << "Tieu de: " << recipe.title << endl;
    cout << "Mo ta: " << recipe.description << endl;
    cout << "Muc do: " << recipe.difficulty << endl;
    cout << "Thoi gian: " << recipe.cookingTime << " phut" << endl;
    cout << "Nguyen lieu: " << recipe.ingredients << endl;
    cout << "Cach lam: " << recipe.instructions << endl;
}

void MenuManager::handleLogin() {
    int choice;
    cout << "\n1. Dang nhap" << endl;
    cout << "2. Dang ky" << endl;
    cout << "Chon: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        string username, password;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        
        User user = accountManager.login(username, password);
        if (user.isLoggedIn()) {
            currentUser = user;
            cout << "Dang nhap thanh cong! Xin chao " << currentUser.getUsername() << " [" << currentUser.getRole() << "]!" << endl;
        } else {
            cout << "Sai username hoac password!" << endl;
        }
    } else if (choice == 2) {
        string username, password, email;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << "Email: ";
        getline(cin, email);
        
        if (accountManager.registerAccount(username, password, email)) {
            cout << "Dang ky thanh cong! Vui long dang nhap." << endl;
        } else {
            cout << "Loi: Khong the dang ky!" << endl;
        }
    }
    
    pause();
}

void MenuManager::pause() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.get();
}
