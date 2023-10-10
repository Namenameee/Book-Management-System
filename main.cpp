#include "Book.h"
#include "Library.h"
#include <iostream>

int main() {
    // 创建几本书籍
    Book book1("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "12345");
    Book book2("The Hobbit", "J.R.R. Tolkien", "67890");
    Book book3("The Great Gatsby", "F. Scott Fitzgerald", "11223");

    // 创建图书馆并添加书籍
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // 显示图书馆中的所有书籍
    std::cout << "Current books in the library:" << std::endl;
    displayAllBooks(library);

    // 保存图书馆数据到 CSV 文件
    library.saveToCSV("books.csv");

    // 清空图书馆并从 CSV 文件加载数据
    Library newLibrary;
    newLibrary.loadFromCSV("books.csv");
    std::cout << "\nBooks loaded from CSV:" << std::endl;
    displayAllBooks(newLibrary);

    // 根据 ISBN 查找书籍
    std::string isbnToSearch = "11223";
    Book* foundBook = newLibrary.findBook(isbnToSearch);
    if (foundBook) {
        std::cout << "\nBook found with ISBN " << isbnToSearch << ":" << std::endl;
        foundBook->display();
    } else {
        std::cout << "\nNo book found with ISBN " << isbnToSearch << "." << std::endl;
    }

    return 0;
}
