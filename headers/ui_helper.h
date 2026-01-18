#ifndef UI_HELPER_H
#define UI_HELPER_H

#include <vector>
#include <string>

using namespace std;

// Vẽ Menu chính và các bảng thông tin
void showMainMenu();
void drawHeader(string title);

// Hàm xử lý file (Utils)
vector<string> splitString(string line, char delimiter);
string joinString(vector<string> fields, char delimiter);

#endif