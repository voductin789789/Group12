#include "../headers/interaction.h"
#include <fstream>
#include <iostream>

using namespace std;

// Đường dẫn các file dữ liệu tương tác
const string PATH_REVIEWS = "data/reviews.txt";
const string PATH_FAVORITES = "data/favorites.txt";

// Chức năng: Thành viên bình luận vào công thức
void Interaction::addComment(int recipeID, int userID, string content) {
    ofstream out(PATH_REVIEWS, ios::app);
    if (!out) {
        cout << "Loi: Khong the ghi nhan binh luan!" << endl;
        return;
    }
    // Định dạng: RecipeID | UserID | Rating (mac dinh 0 khi chi cmt) | Noi dung
    out << recipeID << "|" << userID << "|0|" << content << endl;
    out.close();
    cout << "✅ Da gui binh luan cua ban!" << endl;
}

// Chức năng: Thành viên đánh giá mức độ yêu thích (Rating)
void Interaction::rateRecipe(int recipeID, int userID, int star) {
    if (star < 1 || star > 5) {
        cout << "Loi: Vui long danh gia tu 1 den 5 sao!" << endl;
        return;
    }
    ofstream out(PATH_REVIEWS, ios::app);
    // Luu rating voi noi dung de trong
    out << recipeID << "|" << userID << "|" << star << "|Rating only" << endl;
    out.close();
    cout << "✅ Ban da danh gia " << star << " sao cho cong thuc nay!" << endl;
}

// Chức năng: Quản lý công thức yêu thích (Bookmark)
void Interaction::addToFavorite(int recipeID, int userID) {
    // Kiem tra xem da ton tai trong danh sach yeu thich chua (Logic nang cao co the them sau)
    ofstream out(PATH_FAVORITES, ios::app);
    if (!out) return;

    out << userID << "|" << recipeID << endl;
    out.close();
    cout << "❤️ Da them vao danh sach 'Mon ngon cua toi'!" << endl;
}