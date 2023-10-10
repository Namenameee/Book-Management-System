#include "Library.h"
#include <iostream>
#include <fstream> // 用于文件读写

Library::Library() {}

Library::~Library() {
    std::cout << "Library object destroyed." << std::endl;
}

void Library::loadFromCSV(const std::string& filename) {
    books.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line, title, author, isbn;
    // 跳过第一行（标题行）
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t start = 0, end = line.find(',');
        title = line.substr(start + 1, end - start - 2);  // +1 和 -2 是为了去掉引号

        start = end + 1;
        end = line.find(',', start);
        author = line.substr(start + 1, end - start - 2);

        start = end + 1;
        isbn = line.substr(start);

        books.push_back(Book(title, author, isbn));
    }

    file.close();
}

void Library::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // 写入标题行
    file << "Title,Author,ISBN\n";
    for (const Book& book : books) {
        file << "\"" << book.getTitle() << "\",\"" << book.getAuthor() << "\"," << book.getISBN() << "\n";
    }

    file.close();
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

Book* Library::findBook(const std::string& isbn) {
    for (Book& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

void displayAllBooks(const Library& library) {
    std::cout << "Books in the library:" << std::endl;
    for (const Book& book : library.books) {
        book.display();
    }
}