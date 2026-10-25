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
//const std::vector<int> &Book::getRatings() const {return Ratings;}

// Setters
void Book::setAuthor(const std::string& Author_) {Author = Author_;}
void Book::setTitle(const std::string& Title_) {Title = Title_;}
void Book::setReleaseDate(int ReleaseDate_) {ReleaseDate = ReleaseDate_;}
void Book::setLength(size_t Length_) {Length = Length_;}
//void Book::setRatings(const std::vector<int> &Ratings_) {Ratings = Ratings_;}

/*std::optional<double> Book::getAvgRating() const {
    if (Ratings.empty()) return std::nullopt;
    double sum = 0;
    for (const auto& r : Ratings) sum += r;
    return std::round(sum / static_cast<double>(Ratings.size()) * 100) / 100;
}*/

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

/*bool Book::compareAvgRating(const Book& a, const Book& b) {
    auto ra = a.getAvgRating(), rb = b.getAvgRating();
    if (!ra.has_value()) return false;
    if (!rb.has_value()) return true;
    return *ra > *rb;
}*/

/*bool Book::addRating(int rating) {
    if (rating < 1 || rating > 10) return false;
    Ratings.push_back(rating);
    return true;
}*/

std::ostream& operator<<(std::ostream& os, const Book& book){
    os << "Book Title: " << book.getTitle()
    << "\nAuthor: " << book.getAuthor()
    << "\nRelease Date: " << book.getReleaseDate()
    << "\nLength: " << book.getLength() << "\n";
    /*auto avg = book.getAvgRating();
    if (avg.has_value())
        os << "Average Rating: " << std::fixed << std::setprecision(2) << *avg << "\n";
    else
        os << "Unrated\n";*/
    return os;
}