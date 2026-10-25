#pragma once
#include "Book.hpp"

class BookEntry {
private:
    Book* book;
    int rating;
    const std::string& review;
    bool liked;
    public:
    BookEntry(Book* book, int rating, const std::string& review, bool liked);
};
