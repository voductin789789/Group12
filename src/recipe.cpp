#include "../headers/recipe.h"
#include "../headers/file_manager.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Recipe::getNextRecipeId() {
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    int maxId = 0;
    
    for (const string& line : lines) {
        vector<string> fields = FileManager::splitLine(line);
        if (!fields.empty()) {
            int id = stoi(fields[0]);
            if (id > maxId) {
                maxId = id;
            }
        }
    }
    
    return maxId + 1;
}

bool Recipe::addRecipe(const RecipeData& recipe, const User& currentUser) {
    if (!currentUser.isLoggedIn()) {
        cerr << "Loi: Ban phai dang nhap de them cong thuc!" << endl;
        return false;
    }
    
    RecipeData newRecipe = recipe;
    newRecipe.id = getNextRecipeId();
    newRecipe.authorId = currentUser.getId();
    
    string line = newRecipe.toString();
    bool success = FileManager::appendLine(FileManager::RECIPES_FILE, line);
    
    if (success) {
        cout << "Them cong thuc thanh cong! ID: " << newRecipe.id << endl;
    }
    
    return success;
}

bool Recipe::editRecipe(int id, const RecipeData& newData, const User& currentUser) {
    if (!currentUser.isLoggedIn()) {
        cerr << "Loi: Ban phai dang nhap de sua cong thuc!" << endl;
        return false;
    }
    
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    bool found = false;
    
    for (size_t i = 0; i < lines.size(); ++i) {
        vector<string> fields = FileManager::splitLine(lines[i]);
        
        if (!fields.empty() && stoi(fields[0]) == id) {
            // Kiểm tra quyền (tác giả hoặc admin)
            int authorId = stoi(fields[8]);
            if (currentUser.getId() != authorId && !currentUser.isAdmin()) {
                cerr << "Loi: Ban khong co quyen sua cong thuc nay!" << endl;
                return false;
            }
            
            RecipeData updatedRecipe = newData;
            updatedRecipe.id = id;
            updatedRecipe.authorId = authorId;  // Giữ tác giả cũ
            
            lines[i] = updatedRecipe.toString();
            found = true;
            break;
        }
    }
    
    if (found) {
        FileManager::writeLines(FileManager::RECIPES_FILE, lines);
        cout << "Cap nhat cong thuc thanh cong!" << endl;
        return true;
    }
    
    cerr << "Loi: Khong tim thay cong thuc co ID: " << id << endl;
    return false;
}

bool Recipe::deleteRecipe(int id, const User& currentUser) {
    if (!currentUser.isLoggedIn()) {
        cerr << "Loi: Ban phai dang nhap de xoa cong thuc!" << endl;
        return false;
    }
    
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    auto it = lines.begin();
    
    while (it != lines.end()) {
        vector<string> fields = FileManager::splitLine(*it);
        
        if (!fields.empty() && stoi(fields[0]) == id) {
            // Kiểm tra quyền
            int authorId = stoi(fields[8]);
            if (currentUser.getId() != authorId && !currentUser.isAdmin()) {
                cerr << "Loi: Ban khong co quyen xoa cong thuc nay!" << endl;
                return false;
            }
            
            it = lines.erase(it);
            break;
        } else {
            ++it;
        }
    }
    
    FileManager::writeLines(FileManager::RECIPES_FILE, lines);
    cout << "Xoa cong thuc thanh cong!" << endl;
    return true;
}

RecipeData Recipe::getRecipeById(int id) {
    RecipeData recipe;
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    
    for (const string& line : lines) {
        RecipeData temp = RecipeData::fromString(line);
        if (temp.id == id) {
            return temp;
        }
    }
    
    cerr << "Khong tim thay cong thuc!" << endl;
    return recipe;  // Trả về recipe rỗng
}

vector<RecipeData> Recipe::searchRecipe(const string& keyword) {
    vector<RecipeData> results;
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    
    cout << "\n--- KET QUA TIM KIEM: " << keyword << " ---" << endl;
    
    for (const string& line : lines) {
        // Tìm kiếm trong title, description, hoặc ingredients
        if (line.find(keyword) != string::npos) {
            RecipeData recipe = RecipeData::fromString(line);
            results.push_back(recipe);
            cout << "[" << recipe.id << "] " << recipe.title << " - " << recipe.description << endl;
        }
    }
    
    if (results.empty()) {
        cout << "*** Khong tim thay mon an co tu khoa: " << keyword << " ***" << endl;
    }
    
    return results;
}

vector<RecipeData> Recipe::listAllRecipes() {
    vector<RecipeData> recipes;
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    
    cout << "\n--- DANH SACH CONG THUC ---" << endl;
    
    for (const string& line : lines) {
        RecipeData recipe = RecipeData::fromString(line);
        recipes.push_back(recipe);
        cout << "ID: " << recipe.id << " - Mon: " << recipe.title << endl;
    }
    
    return recipes;
}

vector<RecipeData> Recipe::getRecipesByCategory(int categoryId) {
    vector<RecipeData> recipes;
    vector<string> lines = FileManager::readLines(FileManager::RECIPES_FILE);
    
    for (const string& line : lines) {
        RecipeData recipe = RecipeData::fromString(line);
        if (recipe.categoryId == categoryId) {
            recipes.push_back(recipe);
        }
    }
    
    return recipes;
}