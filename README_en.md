[中文](README.md) | English
# Book Library Project
This project offers a simple book management system, allowing users to manage, search for, and store books.

<div align="center">
<img <img src="https://cdn.mathpix.com/snip/images/5V4kLKp48U2gvrDGdB8LJTMyqunkkWxiD102e4iDM9A.original.fullsize.png" width=350/>
 
</div>

## Project Structure
```
.
|-- main.cpp
|-- Book.h
|-- Book.cpp
|-- Library.h
|-- Library.cpp
`-- books.csv
```

## Features

- Create and manage book objects
- Add books to the library
- Search for books by ISBN number
- Load book data from a `.csv` file
- Save book data to a `.csv` file

## Class Structure

### Book

```
Book
|
|-- Private Members:
|   |-- title (Title)
|   |-- author (Author)
|   `-- isbn (ISBN number)
|
|-- Static Members:
|   `-- bookCount (Count of books)
|
`-- Public Methods:
    |-- Constructor
    |-- Copy Constructor
    |-- Destructor
    |-- getTitle (Get title)
    |-- getAuthor (Get author)
    |-- getISBN (Get ISBN)
    |-- display (Display book information)
    |-- getBookCount (Get count of books)
    |-- operator== (Compare two books)
    `-- User-defined conversion (Convert to string)
```

### Library

```
Library
|
|-- Private Members:
|   `-- books (Vector storing Book objects)
|
`-- Public Methods:
    |-- Constructor
    |-- Destructor
    |-- addBook (Add a book)
    |-- findBook (Search for a book by ISBN)
    |-- loadFromCSV (Load data from .csv file)
    `-- saveToCSV (Save data to .csv file)
```

## How to Use

1. **Create Books**

```cpp
Book book1("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "12345");
Book book2("The Hobbit", "J.R.R. Tolkien", "67890");
```

2. **Create a Library and Add Books**

```cpp
Library library;
library.addBook(book1);
library.addBook(book2);
```

3. **Display All Books in the Library**

```cpp
std::cout << "Current books in the library:" << std::endl;
displayAllBooks(library);
```

4. **Save Library Data to a `.csv` File**

```cpp
library.saveToCSV("path_to_save.csv");
```

5. **Load Library Data from a `.csv` File**

```cpp
Library newLibrary;
newLibrary.loadFromCSV("path_to_csv_file.csv");
```

6. **Search for a Book by ISBN Number**

```cpp
Book* foundBook = newLibrary.findBook("12345");
if (foundBook) {
    foundBook->display();
}
```

The above code snippets can be found in `main.cpp` and provide a basic example of how to use this project.

## Note

Ensure the format of the `.csv` file matches the sample file `books.csv`.
