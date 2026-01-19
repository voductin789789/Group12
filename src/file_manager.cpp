#include "../headers/file_manager.h"
#include <fstream>
#include <iostream>

using namespace std;

// Định nghĩa các hằng số
const string FileManager::DATA_DIR = "data/";
const string FileManager::ACCOUNTS_FILE = "data/accounts.txt";
const string FileManager::RECIPES_FILE = "data/recipes.txt";
const string FileManager::CATEGORIES_FILE = "data/categories.txt";
const string FileManager::REVIEWS_FILE = "data/reviews.txt";
const string FileManager::FAVORITES_FILE = "data/favorites.txt";

vector<string> FileManager::readLines(const string& filePath) {
    vector<string> lines;
    ifstream file(filePath);
    
    if (!file.is_open()) {
        cerr << "Loi: Khong the mo file: " << filePath << endl;
        return lines;
    }
    
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    
    file.close();
    return lines;
}

bool FileManager::appendLine(const string& filePath, const string& line) {
    ofstream file(filePath, ios::app);
    
    if (!file.is_open()) {
        cerr << "Loi: Khong the mo file: " << filePath << endl;
        return false;
    }
    
    file << line << endl;
    file.close();
    return true;
}

bool FileManager::writeLines(const string& filePath, const vector<string>& lines) {
    ofstream file(filePath, ios::trunc);
    
    if (!file.is_open()) {
        cerr << "Loi: Khong the mo file: " << filePath << endl;
        return false;
    }
    
    for (const string& line : lines) {
        file << line << endl;
    }
    
    file.close();
    return true;
}

vector<string> FileManager::splitLine(const string& line, char delimiter) {
    vector<string> fields;
    stringstream ss(line);
    string field;
    
    while (getline(ss, field, delimiter)) {
        fields.push_back(field);
    }
    
    return fields;
}

string FileManager::joinFields(const vector<string>& fields, char delimiter) {
    string result;
    for (size_t i = 0; i < fields.size(); ++i) {
        result += fields[i];
        if (i < fields.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}
