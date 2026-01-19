#ifndef RECIPE_DATA_H
#define RECIPE_DATA_H

#include <string>

using namespace std;

// Cấu trúc dữ liệu cho một công thức
struct RecipeData {
    int id;
    string title;
    string description;
    string ingredients;
    string instructions;
    int cookingTime;        // phút
    string difficulty;      // EASY, MEDIUM, HARD
    int categoryId;
    int authorId;
    
    // Constructor
    RecipeData() : id(0), cookingTime(0), categoryId(0), authorId(0) {}
    
    // Convert to file format
    string toString() const;
    
    // Parse from file format
    static RecipeData fromString(const string& line);
};

#endif
