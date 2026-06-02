#include "Book.hpp"
#include <cmath>

// Constructor
Book::Book(const std::string& Title,
           const std::string& Author,
           int ReleaseDate,
           size_t Length)
    : Title(Title),
      Author(Author),
      ReleaseDate(ReleaseDate),
      Length(Length)
{}

// Getters
const std::string& Book::getAuthor() const {return Author;}
const std::string& Book::getTitle() const {return Title;}
int Book::getReleaseDate() const {return ReleaseDate;}
size_t Book::getLength() const {return Length;}
const std::vector<int> &Book::getRatings() const {return Ratings;}

// Setters
void Book::setAuthor(const std::string& Author_) {Author = Author_;}
void Book::setTitle(const std::string& Title_) {Title = Title_;}
void Book::setReleaseDate(int ReleaseDate_) {ReleaseDate = ReleaseDate_;}
void Book::setLength(size_t Length_) {Length = Length_;}
void Book::setRatings(const std::vector<int> &Ratings_) {Ratings = Ratings_;}

double Book::getAvgRating() const {
    if (Ratings.empty()) {
        return 0.0;
    }
    double sum = 0;
    for (const auto& rating : Ratings) {
        sum += rating;
    }
    return std::round(sum / static_cast<double>(Ratings.size()) * 100)/100;
}

bool Book::compareDate(const Book &book1, const Book &book2) {
    if (book1.getReleaseDate()<book2.getReleaseDate()) {
        return true;
    }
    else if (book1.getReleaseDate()==book2.getReleaseDate()) {
        return book1.getTitle() < book2.getTitle();
    }
    else {
        return false;
    }
}

bool Book::compareAvgRating(const Book &book1, const Book &book2) {
    return book1.getAvgRating() > book2.getAvgRating();
}

Book &Book::operator+(const double rating) {
    Ratings.push_back(rating);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Book& book){
    os << "Book Title: " << book.getTitle()
    << "\nAuthor: " << book.getAuthor()
    << "\nRelease Date: " << book.getReleaseDate()
    << "\nLength: " << book.getLength() << std::endl;
    os << "Average Rating: " <<  book.getAvgRating() << std::endl;
    return os;
}