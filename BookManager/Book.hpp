#pragma once
#include <string>
#include <optional>
#include <stdexcept>
#include <variant>
#include <iostream>
#include <ostream>

class Book {

public:

    enum class ReadingState {
        PlanToRead,
        Reading,
        Complete,
        Dropped
    };

private:

    std::string Author;
    std::string Title;
    int ReleaseDate;
    size_t Length;
    std::optional<int> Rating;
    std::optional<bool> Liked;
    ReadingState State;

public:

    // Constructor
    Book(const std::string& Author,
         const std::string& Title,
         int ReleaseDate,
         size_t Length,
         std::optional<int> Rating,
         std::optional<bool> Liked,
         ReadingState State);

    Book(const std::string& Author,
         const std::string& Title,
         int ReleaseDate,
         size_t Length,
         ReadingState State);

    // Getters
    const std::string& getAuthor() const;
    const std::string& getTitle() const;
    int getReleaseDate() const;
    size_t getLength() const;
    std::optional<int> getRating() const;
    std::optional<bool> getLiked() const;
    ReadingState getReadingState() const;

    // Setters
    void setAuthor(const std::string& Author);
    void setTitle(const std::string& Title);
    void setReleaseDate(int ReleaseDate);
    void setLength(size_t Length);
    void setRating(std::optional<int> Rating);
    void setLiked(std::optional<bool> Liked);
    void setReadingState(ReadingState State);

    std::string getReadingStateString() const;
};

std::ostream& operator<<(std::ostream& os, const Book& book);