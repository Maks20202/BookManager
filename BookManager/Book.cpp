#include "Book.hpp"

// Constructor
Book::Book(const std::string& Author,
           const std::string& Title,
           int ReleaseDate,
           size_t Length,
           std::optional<int> Rating,
           std::optional<bool> Liked,
           ReadingState State)
    : Author(Author),
      Title(Title),
      ReleaseDate(ReleaseDate),
      Length(Length),
      Rating(Rating),
      Liked(Liked),
      State(State)
{
    if (State == ReadingState::PlanToRead &&
     (Rating.has_value() || Liked.has_value()))
    {
        throw std::invalid_argument(
            "Unread books cannot have ratings or liked status"
        );
    }
}

Book::Book(const std::string& Author,
         const std::string& Title,
         int ReleaseDate,
         size_t Length,
         ReadingState State)
: Author(Author),
  Title(Title),
  ReleaseDate(ReleaseDate),
  Length(Length),
  State(State){}

// Getters
const std::string& Book::getAuthor() const {return Author;}
const std::string& Book::getTitle() const {return Title;}
int Book::getReleaseDate() const {return ReleaseDate;}
size_t Book::getLength() const {return Length;}
std::optional<int> Book::getRating() const {return Rating;}
std::optional<bool> Book::getLiked() const {return Liked;}
Book::ReadingState Book::getReadingState() const {return State;}

// Setters
void Book::setAuthor(const std::string& Author_) {Author = Author_;}
void Book::setTitle(const std::string& Title_) {Title = Title_;}
void Book::setReleaseDate(int ReleaseDate_) {ReleaseDate = ReleaseDate_;}
void Book::setLength(size_t Length_) {Length = Length_;}
void Book::setRating(std::optional<int> Rating_) {Rating = Rating_;}
void Book::setLiked(std::optional<bool> Liked_) {Liked = Liked_;}
void Book::setReadingState(ReadingState State_) {State = State_;}

std::string Book::getReadingStateString() const {
    switch (State) {
        case ReadingState::PlanToRead:
            return "PlanToRead";
        case ReadingState::Reading:
            return "Reading";
        case ReadingState::Dropped:
            return "Dropped";
        case ReadingState::Complete:
            return "Complete";
    }
    return "Unknown";
}

std::ostream& operator<<(std::ostream& os, const Book& book){
    os << "Book Title: " << book.getTitle()
    << "\nAuthor: " << book.getAuthor()
    << "\nRelease Date: " << book.getReleaseDate()
    << "\nLength: " << book.getLength() << std::endl;
    if (book.getLiked().has_value() && book.getRating().has_value()) {
        os << "Rating: " << book.getRating().value() <<std::endl;
        if (book.getLiked().value()) {
            os << "Liked" << std::endl;
        }
        else {
            os << "Not Liked" << std::endl;
        }
    }
    os << book.getReadingStateString() << std::endl;
    return os;
}