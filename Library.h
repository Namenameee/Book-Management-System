#pragma once
#include "Book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    // 构造函数
    Library();

    // 析构函数
    ~Library();
    
    // 从 CSV 文件加载书籍数据
    void loadFromCSV(const std::string& filename);

    // 将书籍数据保存到 CSV 文件
    void saveToCSV(const std::string& filename) const;

    // 添加一本书到图书馆
    void addBook(const Book& book);

    // 根据 ISBN 查找一本书
    Book* findBook(const std::string& isbn);

    // 为 Book 类定义一个 friend 函数，以显示图书馆中的所有书籍
    friend void displayAllBooks(const Library& library);
};

