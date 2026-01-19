# Refactored Code - Cải Tiến Cấu Trúc

## Tóm Tắt Cải Tiến

Refactor code để cải thiện cấu trúc, dễ bảo trì, và mở rộng trong tương lai.

### 1. **Tách Lớp Quản Lý File (FileManager)**
- **Trước**: Mỗi class tự đọc/ghi file riêng lẻ
- **Sau**: Tập trung quản lý I/O tại `FileManager`
- **Lợi ích**: 
  - Dễ bảo trì đường dẫn file
  - Tái sử dụng code parsing
  - Lỗi file I/O được xử lý tập trung

### 2. **Tạo Class User Quản Lý Trạng Thái Đăng Nhập**
- **Trước**: `Account` lưu trữ username/role cục bộ
- **Sau**: `User` class đại diện cho user instance
- **Lợi ích**:
  - Tách rõ authentication (Account) và user state (User)
  - Dễ quản lý session
  - Có method `isLoggedIn()`, `isAdmin()`, `logout()`

### 3. **Tạo RecipeData Struct**
- **Trước**: Recipe class chứa cả dữ liệu và logic
- **Sau**: `RecipeData` struct + `Recipe` manager
- **Lợi ích**:
  - Dữ liệu tách biệt với logic
  - Dễ serialize/deserialize
  - Method `toString()` và `fromString()`

### 4. **Tạo MenuManager Quản Lý UI/Flow**
- **Trước**: main() chứa tất cả switch statements
- **Sau**: `MenuManager` xử lý tất cả menu logic
- **Lợi ích**:
  - main.cpp sạch sẽ, ngắn gọn
  - Dễ thêm menu mới
  - Phân tách responsibilities

### 5. **Cải Tiến Account/Authentication**
- Thêm `userExists()` check
- Thêm `getUserById()` 
- Reset password thực sự cập nhật file
- Return User object thay vì boolean

### 6. **Cải Tiến Recipe Manager**
- Thêm phân quyền: chỉ tác giả/admin được edit/delete
- Method mới: `getRecipesByCategory()`
- Xử lý ID tự động tăng
- Return vector<RecipeData> thay vì in ra console

### 7. **Error Handling**
- Thêm kiểm tra file tồn tại
- Thêm kiểm tra quyền
- Thêm validation đầu vào

### 8. **Code Style**
- Hàm const correctness
- Tham số pass by reference
- Đặt tên biến rõ ràng
- Comment Vietnamese rõ ràng

## Cấu Trúc File Mới

```
headers/
├── file_manager.h      ✨ NEW - Quản lý file I/O
├── user.h              ✨ NEW - Trạng thái user
├── recipe_data.h       ✨ NEW - Dữ liệu recipe
├── menu_manager.h      ✨ NEW - Quản lý menu UI
├── auth.h              📝 CẬP NHẬT - Sử dụng User
├── recipe.h            📝 CẬP NHẬT - Sử dụng RecipeData
├── category.h          (không đổi)
├── interaction.h       (không đổi)
└── ui_helper.h         (không đổi)

src/
├── file_manager.cpp    ✨ NEW
├── user.cpp            ✨ NEW
├── recipe_data.cpp     ✨ NEW
├── menu_manager.cpp    ✨ NEW
├── auth.cpp            📝 CẬP NHẬT
├── recipe.cpp          📝 CẬP NHẬT
├── category.cpp        (không đổi)
├── interaction.cpp     (không đổi)
└── ui_helper.cpp       (không đổi)

untils/
└── main.cpp            📝 CẬP NHẬT - Rất ngắn gọn
```

## Ví Dụ Sử Dụng

### Trước (Cũ)
```cpp
Account currentUser;
if (currentUser.login(u, p)) {
    cout << currentUser.getUsername();  // Có sẽ tìm được username
}
// Không rõ user có đăng nhập không
```

### Sau (Mới)
```cpp
User user = accountManager.login(username, password);
if (user.isLoggedIn()) {
    recipeManager.addRecipe(recipe, user);  // Truyền user vào
}
```

## Bước Tiếp Theo

1. Kiểm tra biên dịch không lỗi
2. Compile các file mới vào project
3. Test login/register
4. Test add/edit/delete recipe
5. Push code lên GitHub

## Lưu Ý

- Đảm bảo file `data/accounts.txt` tồn tại
- File `data/recipes.txt` cần có format đúng
- Tất cả file dữ liệu sử dụng delimiter `|`
