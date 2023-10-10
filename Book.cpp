#include "Book.h"
#include <iostream>

int Book::bookCount = 0;

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title(title), author(author), isbn(isbn) {
    bookCount++;
}

Book::Book(const Book& other)
    : title(other.title), author(other.author), isbn(other.isbn) {
    bookCount++;
}

Book::~Book() {
    bookCount--;
    std::cout << "Book with ISBN: " << isbn << " destroyed." << std::endl;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

void Book::display() const {
    std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
}

int Book::getBookCount() {
    return bookCount;
}

bool Book::operator==(const Book& other) const {
    return isbn == other.isbn;
}

Book::operator std::string() const {
    return "Title: " + title + ", Author: " + author + ", ISBN: " + isbn;
}
