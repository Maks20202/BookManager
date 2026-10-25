#include "BookList.hpp"
#include <algorithm>
#include <cmath>

BookList::BookList(const std::string& name): name(name) {}

const std::string &BookList::getName() const {return name;}
const std::vector<Book>& BookList::getBooks() const {return books;}

void BookList::addBook(const Book& book) {
    books.push_back(book);
}

/*std::optional<double> BookList::getAverageRating() const {
    double sum = 0;
    int count = 0;

    for (const auto& book : books) {
        auto rating = book.getAvgRating();
        if (rating.has_value()) {
            sum += *rating;
            count++;
        }
    }

    if (count == 0) return std::nullopt;  // no books have been rated at all
    return std::round(sum / static_cast<double>(count) * 100) / 100;
}*/

/*void BookList::sortByRating() {
    std::sort(books.begin(), books.end(), Book::compareAvgRating);
}*/

void BookList::sortByDate() {
    std::sort(books.begin(), books.end(), Book::compareDate);
}

std::ostream& operator<<(std::ostream& os, const BookList& booklist) {
    os << "-------" << booklist.getName() << "-------\n";
    /*auto avg = booklist.getAverageRating();
    if (avg.has_value())
        os << "Average list rating: " << std::fixed << std::setprecision(2) << *avg << "\n";
    else
        os << "Unrated\n";
    os << "\n";*/
    for (const auto& book : booklist.getBooks())
        os << book << "\n";
    return os;
}