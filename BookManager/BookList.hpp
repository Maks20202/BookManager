#pragma once
#include "Book.hpp"

class BookList {
    std::vector<Book> books;
    std::string name;

    public:

    BookList(const std::string& name);

    const std::string& getName() const;
    const std::vector<Book>& getBooks() const;

    void addBook(const Book& book);
    double getAverageRating() const;
    void sortByRating();
    void sortByDate();
};

std::ostream& operator<<(std::ostream& os, const BookList& books);