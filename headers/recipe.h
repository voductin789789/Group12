#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include "recipe_data.h"
#include "user.h"

using namespace std;

// Quản lý các công thức nấu ăn
class Recipe {
public:
    // Thêm công thức mới (cần người dùng đã đăng nhập)
    bool addRecipe(const RecipeData& recipe, const User& currentUser);
    
    // Sửa công thức (chỉ tác giả hoặc admin mới được)
    bool editRecipe(int id, const RecipeData& newData, const User& currentUser);
    
    // Xóa công thức
    bool deleteRecipe(int id, const User& currentUser);
    
    // Xem chi tiết một công thức
    RecipeData getRecipeById(int id);
    
    // Tìm kiếm công thức theo từ khóa
    vector<RecipeData> searchRecipe(const string& keyword);
    
    // Liệt kê tất cả công thức
    vector<RecipeData> listAllRecipes();
    
    // Lấy công thức theo danh mục
    vector<RecipeData> getRecipesByCategory(int categoryId);

private:
    // Lấy ID mới cho công thức
    int getNextRecipeId();
};

#endif