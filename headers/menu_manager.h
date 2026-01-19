#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include <string>
#include "user.h"
#include "auth.h"
#include "recipe.h"
#include "category.h"
#include "interaction.h"

using namespace std;

// Quản lý tất cả các menu và luồng tương tác
class MenuManager {
private:
    Account accountManager;
    Recipe recipeManager;
    Category categoryManager;
    Interaction interactionManager;
    User currentUser;
    bool isRunning;

public:
    MenuManager();
    
    // Chạy main loop
    void run();
    
    // Menu chính
    void showMainMenu();
    
    // Menu cho user đã đăng nhập
    void showUserMenu();
    
    // Menu quản trị viên
    void showAdminMenu();
    
    // Các menu con
    void handleLogin();
    void handleRegister();
    void handleSearch();
    void handleViewRecipes();
    void handleAddRecipe();
    void handleEditRecipe();
    void handleDeleteRecipe();
    void handleViewRecipeDetail(int recipeId);
    
    // Utility
    void pause();
    bool isUserLoggedIn() const { return currentUser.isLoggedIn(); }
    const User& getCurrentUser() const { return currentUser; }
};

#endif
