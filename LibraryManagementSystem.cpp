#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::remove

class Book {
private:
    int bookID;
    std::string author;
    bool isAvailable;

public:
    Book(int id, std::string auth) : bookID(id), author(auth), isAvailable(true) {}

    void displayDetails() const {
        std::cout << "Book ID: " << bookID << ", Author: " << author
                  << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }

    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        isAvailable = true;
    }

    int getBookID() const {
        return bookID;
    }

    bool getAvailability() const {
        return isAvailable;
    }
};

class User {
protected:
    int userID;
    std::string name;
    std::string userType;
    std::vector<int> borrowedBooks;

public:
    User(int id, const std::string& n, const std::string& type)
        : userID(id), name(n), userType(type) {}

    virtual ~User() = default;

    virtual bool borrow(Book& b) = 0;
    virtual void returnBook(Book& b) = 0;

    std::vector<int> getBorrowedBooks() const {
        return borrowedBooks;
    }
};

class Student : public User {
public:
    Student(int id, const std::string& n) : User(id, n, "Student") {}

    bool borrow(Book& b) override {
        if (borrowedBooks.size() < 3 && b.borrowBook()) {
            borrowedBooks.push_back(b.getBookID());
            return true;
        }
        return false;
    }

    void returnBook(Book& b) override {
        b.returnBook();
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), b.getBookID()), borrowedBooks.end());
    }
};

class Faculty : public User {
public:
    Faculty(int id, const std::string& n) : User(id, n, "Faculty") {}

    bool borrow(Book& b) override {
        if (borrowedBooks.size() < 5 && b.borrowBook()) {
            borrowedBooks.push_back(b.getBookID());
            return true;
        }
        return false;
    }

    void returnBook(Book& b) override {
        b.returnBook();
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), b.getBookID()), borrowedBooks.end());
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void displayAvailableBooks() const {
        for (const auto& book : books) {
            if (book.getAvailability()) {
                book.displayDetails();
            }
        }
    }

    Book* findBookByID(int id) {
        for (auto& book : books) {
            if (book.getBookID() == id) {
                return &book;
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;
    library.addBook(Book(1, "Author A"));
    library.addBook(Book(2, "Author B"));
    library.addBook(Book(3, "Author C"));

    Student student(1, "Student One");
    Faculty faculty(2, "Faculty One");

    int choice;
    do {
        std::cout << "Library Management System\n";
        std::cout << "1. Borrow Book (Student)\n";
        std::cout << "2. Return Book (Student)\n";
        std::cout << "3. Borrow Book (Faculty)\n";
        std::cout << "4. Return Book (Faculty)\n";
        std::cout << "5. Display Available Books\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int bookID;
        switch (choice) {
            case 1:
                std::cout << "Enter Book ID to borrow: ";
                std::cin >> bookID;
                if (library.findBookByID(bookID) && student.borrow(*library.findBookByID(bookID))) {
                    std::cout << "Book borrowed successfully.\n";
                } else {
                    std::cout << "Book is not available or limit reached.\n";
                }
                break;
            case 2:
                std::cout << "Enter Book ID to return: ";
                std::cin >> bookID;
                student.returnBook(*library.findBookByID(bookID));
                std::cout << "Book returned successfully.\n";
                break;
            case 3:
                std::cout << "Enter Book ID to borrow: ";
                std::cin >> bookID;
                if (library.findBookByID(bookID) && faculty.borrow(*library.findBookByID(bookID))) {
                    std::cout << "Book borrowed successfully.\n";
                } else {
                    std::cout << "Book is not available or limit reached.\n";
                }
                break;
            case 4:
                std::cout << "Enter Book ID to return: ";
                std::cin >> bookID;
                faculty.returnBook(*library.findBookByID(bookID));
                std::cout << "Book returned successfully.\n";
                break;
            case 5:
                std::cout << "Available Books:\n";
                library.displayAvailableBooks();
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
