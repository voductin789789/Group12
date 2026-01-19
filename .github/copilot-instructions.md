# Copilot Instructions - Recipe Sharing Application

## Project Overview
This is a Vietnamese recipe sharing application built in C++ with a console-based UI. The system manages user accounts, recipes, categories, and user interactions (reviews, favorites, comments). Data is persisted in pipe-delimited text files.

## Architecture

### Core Components (src/ and headers/)
- **Account (auth.h/auth.cpp)**: User authentication and registration using `data/accounts.txt`
  - Data format: `id|username|password|email|role` (roles: ADMIN, MEMBER)
  - Pattern: Direct file I/O with line-by-line parsing using `stringstream` and `getline(ss, var, '|')`
- **Recipe (recipe.h/recipe.cpp)**: Recipe CRUD operations and search functionality
  - Data format: `id|title|description|ingredients|instructions|cookingTime|difficulty|categoryID|authorID`
  - Manages recipes in `data/recipes.txt`
- **Category (category.h/category.cpp)**: Recipe categorization (danh mục)
  - Data in `data/categories.txt`
- **Interaction (interaction.h/interaction.cpp)**: Comments, ratings, favorites
  - Data: `data/reviews.txt` (ratings/comments) and `data/favorites.txt` (user favorites)
- **UI Helper (ui_helper.h/ui_helper.cpp)**: Console menus and string utilities
  - `showMainMenu()` displays 4-option main menu (search, categories, login, exit)
  - `splitString()` / `joinString()` handle pipe-delimited parsing

### Data Flow
1. `main.cpp` (untils/ directory - likely a typo, should be utils/) instantiates managers
2. Main loop switches on user choice, delegates to appropriate manager class
3. Each manager reads from/writes to corresponding data files in `data/`
4. UI helper provides string utilities and menu rendering

## Key Patterns & Conventions

### File I/O & Parsing
- **Pipe-delimited format**: All data files use `|` as delimiter
- **Parsing**: Use `stringstream` with `getline(ss, var, '|')` to extract fields
- **Paths**: Relative paths like `"data/accounts.txt"` work from project root
- **Example** (from auth.cpp):
  ```cpp
  while (getline(in, line)) {
      stringstream ss(line);
      getline(ss, id, '|');
      getline(ss, u, '|');
      getline(ss, p, '|');
      getline(ss, email, '|');
      getline(ss, r, '|');
  }
  ```

### Class Design
- Managers are instantiated globally in `main()` and control their own data files
- No shared database layer; each class handles file I/O independently
- No explicit validation; assumes well-formed input data
- No error handling for file operations (crashes if files missing)

### Vietnamese Naming & UI
- Comments and strings use Vietnamese (tiếng Việt)
- Menu options, user prompts, and role names are in Vietnamese
- When adding features, maintain Vietnamese comments and user-facing text

### ID Management
- Fixed IDs in `accounts.txt` start at 1
- Recipe registration creates new IDs (e.g., "100" prefix noted in registerAccount)
- No auto-increment logic; simplistic for group project scope

## Development Workflow

### Building
- Compile with: `g++ untils/main.cpp src/*.cpp -o recipe_app.exe` (or use existing executable)
- Executable exists at project root as `recipe_app.exe`

### Testing Changes
- Run recipe_app.exe and test menu options
- Verify file reading/writing to data/ directory
- Manual testing only; no test framework

### Adding New Features
1. Add method to appropriate header (auth.h, recipe.h, category.h, interaction.h)
2. Implement in corresponding .cpp file with same pipe-delimited file I/O pattern
3. Add menu option in `main.cpp` switch statement
4. Add UI helper function if new menu needed

## Important Integration Points

- **Authentication**: Check `currentUser.getRole()` (ADMIN vs MEMBER) for permission gates
- **File Encoding**: Data files use UTF-8; Vietnamese diacritics must be preserved
- **No Transactions**: Changes immediately written to files; no rollback or locking
- **Relative Paths**: All data file paths are relative; execute from project root

## Common Pitfalls
- Forgetting `cin.ignore()` after `cin >>` before `getline()`
- File pointers not closed; always use scope-based file closing or explicit `close()`
- IDs not validated; duplicates possible if carelessly added
