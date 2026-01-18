#include "../headers/recipe.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const string PATH_RECIPES = "data/recipes.txt";

void Recipe::addRecipe() {
    cout << "Them cong thuc moi (chua implement)" << endl;
}

void Recipe::editRecipe(int id) {
    cout << "Sua cong thuc (chua implement)" << endl;
}

void Recipe::deleteRecipe(int id) {
    cout << "Xoa cong thuc (chua implement)" << endl;
}

void Recipe::viewDetail(int id) {
    ifstream in(PATH_RECIPES);
    string line;
    bool found = false;
    while (getline(in, line)) {
        stringstream ss(line);
        string rID, t, d, ing, ins, time, diff, cID, aID;
        
        getline(ss, rID, '|');
        if (stoi(rID) == id) {
            getline(ss, t, '|');
            getline(ss, d, '|');
            getline(ss, ing, '|');
            getline(ss, ins, '|');
            getline(ss, time, '|');
            getline(ss, diff, '|');
            
            cout << "\n--- CHI TIET CONG THUC ---" << endl;
            cout << "Ten mon: " << t << " [" << diff << "]" << endl;
            cout << "Thoi gian nau: " << time << " phut" << endl;
            cout << "Nguyen lieu: " << ing << endl;
            cout << "Cach lam: " << ins << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay cong thuc!" << endl;
}

void Recipe::searchRecipe(string keyword) {
    ifstream in(PATH_RECIPES);
    if (!in) {
        cout << "Loi: Khong tim thay file recipes!" << endl;
        return;
    }
    string line;
    cout << "\n--- KET QUA TIM KIEM: " << keyword << " ---" << endl;
    bool found = false;
    while (getline(in, line)) {
        if (line.find(keyword) != string::npos) {
            stringstream ss(line);
            string rID, t, desc;
            getline(ss, rID, '|');
            getline(ss, t, '|');
            getline(ss, desc, '|');
            cout << "[" << rID << "] " << t << " - " << desc << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "*** Khong tim thay mon an co tu khoa: " << keyword << " ***" << endl;
    }
    in.close();
}

void Recipe::listAllRecipes() {
    ifstream in(PATH_RECIPES);
    string line;
    cout << "\n--- DANH SACH CONG THUC ---" << endl;
    while (getline(in, line)) {
        stringstream ss(line);
        string rID, t;
        getline(ss, rID, '|');
        getline(ss, t, '|');
        cout << "ID: " << rID << " - Mon: " << t << endl;
    }
}