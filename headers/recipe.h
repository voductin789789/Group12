#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Recipe {
private:
    int recipeID;
    string title;
    string description;
    string ingredients;
    string instructions;
    int cookingTime;
    string difficulty;
    int categoryID;
    int authorID;

public:
    void addRecipe();
    void editRecipe(int id);
    void deleteRecipe(int id);
    void viewDetail(int id);
    void searchRecipe(string keyword);
    void listAllRecipes();
};

#endif