中文 | [English](README_en.md)
# 书籍图书馆项目

这个项目提供了一个简单的书籍管理系统，允许用户管理、查询和存储书籍。

##项目结构
```
.
|-- main.cpp
|-- Book.h
|-- Book.cpp
|-- Library.h
|-- Library.cpp
`-- books.csv
```
## 功能

- 创建和管理书籍对象
- 将书籍添加到图书馆
- 根据 ISBN 号码查找书籍
- 从 `.csv` 文件中加载书籍数据
- 将书籍数据保存到 `.csv` 文件

## 类结构

### Book

```
Book
|
|-- Private Members:
|   |-- title (书名)
|   |-- author (作者)
|   `-- isbn (ISBN 号码)
|
|-- Static Members:
|   `-- bookCount (记录书的数量)
|
`-- Public Methods:
    |-- 构造函数
    |-- 拷贝构造函数
    |-- 析构函数
    |-- getTitle (获取书名)
    |-- getAuthor (获取作者)
    |-- getISBN (获取 ISBN)
    |-- display (显示书籍信息)
    |-- getBookCount (获取书的数量)
    |-- operator== (比较两本书)
    `-- 用户定义的转换 (转换为字符串)
```

### Library

```
Library
|
|-- Private Members:
|   `-- books (存储 Book 对象的向量)
|
`-- Public Methods:
    |-- 构造函数
    |-- 析构函数
    |-- addBook (添加书籍)
    |-- findBook (根据 ISBN 查找书籍)
    |-- loadFromCSV (从 .csv 文件加载数据)
    `-- saveToCSV (保存数据到 .csv 文件)
```


## 如何使用

1. **创建书籍**

```cpp
Book book1("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "12345");
Book book2("The Hobbit", "J.R.R. Tolkien", "67890");
```

2. **创建图书馆并添加书籍**

```cpp
Library library;
library.addBook(book1);
library.addBook(book2);
```

3. **显示图书馆中的所有书籍**

```cpp
std::cout << "Current books in the library:" << std::endl;
displayAllBooks(library);
```

4. **保存图书馆数据到 `.csv` 文件**

```cpp
library.saveToCSV("path_to_save.csv");
```

5. **从 `.csv` 文件中加载图书馆数据**

```cpp
Library newLibrary;
newLibrary.loadFromCSV("path_to_csv_file.csv");
```

6. **根据 ISBN 号码查找书籍**

```cpp
Book* foundBook = newLibrary.findBook("12345");
if (foundBook) {
    foundBook->display();
}
```

以上的代码片段可以在 `main.cpp` 中找到，并提供了如何使用这个项目的基本示例。


## 注意事项

确保 `.csv` 文件的格式与示例文件 `books.csv` 相匹配。
