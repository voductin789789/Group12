#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Quản lý tất cả các file I/O
class FileManager {
public:
    static const string DATA_DIR;
    static const string ACCOUNTS_FILE;
    static const string RECIPES_FILE;
    static const string CATEGORIES_FILE;
    static const string REVIEWS_FILE;
    static const string FAVORITES_FILE;

    // Đọc tất cả các dòng từ file
    static vector<string> readLines(const string& filePath);
    
    // Ghi dòng vào file (append)
    static bool appendLine(const string& filePath, const string& line);
    
    // Ghi toàn bộ dữ liệu (overwrite)
    static bool writeLines(const string& filePath, const vector<string>& lines);
    
    // Tách string theo delimiter
    static vector<string> splitLine(const string& line, char delimiter = '|');
    
    // Nối vector thành string
    static string joinFields(const vector<string>& fields, char delimiter = '|');
};

#endif
