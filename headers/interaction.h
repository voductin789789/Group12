#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>
#include <vector>

using namespace std;

class Interaction {
public:
    void addComment(int recipeID, int userID, string content); // Thành viên bình luận
    void rateRecipe(int recipeID, int userID, int star);      // Thành viên đánh giá
    void addToFavorite(int recipeID, int userID);            // Quản lý công thức yêu thích
};

#endif