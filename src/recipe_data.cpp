#include "../headers/recipe_data.h"
#include "../headers/file_manager.h"
#include <sstream>

using namespace std;

string RecipeData::toString() const {
    vector<string> fields = {
        to_string(id),
        title,
        description,
        ingredients,
        instructions,
        to_string(cookingTime),
        difficulty,
        to_string(categoryId),
        to_string(authorId)
    };
    return FileManager::joinFields(fields);
}

RecipeData RecipeData::fromString(const string& line) {
    RecipeData recipe;
    vector<string> fields = FileManager::splitLine(line);
    
    if (fields.size() >= 9) {
        recipe.id = stoi(fields[0]);
        recipe.title = fields[1];
        recipe.description = fields[2];
        recipe.ingredients = fields[3];
        recipe.instructions = fields[4];
        recipe.cookingTime = stoi(fields[5]);
        recipe.difficulty = fields[6];
        recipe.categoryId = stoi(fields[7]);
        recipe.authorId = stoi(fields[8]);
    }
    
    return recipe;
}
