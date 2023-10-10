#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

    static int bookCount; // 静态成员，记录书的数量

public:
    // 构造函数
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    // 拷贝构造函数
    Book(const Book& other);

    // 析构函数
    ~Book();

    // 获取书的标题
    std::string getTitle() const;

    // 获取书的作者
    std::string getAuthor() const;

    // 获取书的ISBN
    std::string getISBN() const;

    // 显示书的详细信息
    void display() const;

    // 静态函数，获取书的数量
    static int getBookCount();

    // 重载==运算符，比较两本书是否相同
    bool operator==(const Book& other) const;

    // 用户定义的转换，将书转换为字符串
    operator std::string() const;
};

