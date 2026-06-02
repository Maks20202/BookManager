#include "BookList.hpp"
#include <algorithm>
#include <cmath>

BookList::BookList(const std::string& name): name(name) {}

const std::string &BookList::getName() const {return name;}
const std::vector<Book>& BookList::getBooks() const {return books;}

void BookList::addBook(const Book& book) {
    books.push_back(book);
}

double BookList::getAverageRating() const{
    double sum = 0;
    for (auto& book : books) {
        sum += book.getAvgRating();
    }
    return std::round(sum / static_cast<double>(books.size()) * 100)/100;
}

void BookList::sortByRating() {
    std::sort(books.begin(), books.end(), Book::compareAvgRating);
}

void BookList::sortByDate() {
    std::sort(books.begin(), books.end(), Book::compareDate);
}

std::ostream& operator<<(std::ostream& os, const BookList& books) {
    const auto& cosek = books.getBooks();
    os << "-------" << books.getName() << "-------" << std::endl;
    os << "Average list rating: " << books.getAverageRating() << std::endl;
    os << std::endl;
    for (auto& book : cosek) {
        os << book << std::endl;
    }
    return os;
}