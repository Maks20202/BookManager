#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <optional>
#include <iomanip>


class Book {

private:

    std::string Title;
    std::string Author;
    int ReleaseDate;
    size_t Length;
    //std::vector<int> Ratings;

public:

    // Constructor
    Book(const std::string& Title,
         const std::string& Author,
         int ReleaseDate,
         size_t Length);

    // Getters
    const std::string& getAuthor() const;
    const std::string& getTitle() const;
    int getReleaseDate() const;
    size_t getLength() const;
    //const std::vector<int>& getRatings() const;

    // Setters
    void setAuthor(const std::string& Author);
    void setTitle(const std::string& Title);
    void setReleaseDate(int ReleaseDate);
    void setLength(size_t Length);
    //void setRatings(const std::vector<int>& Ratings);

    //std::optional<double> getAvgRating() const;
    static bool compareDate(const Book& book1, const Book& book2);
    //static bool compareAvgRating(const Book& a, const Book& b);
    //bool addRating(int rating);
};

std::ostream& operator<<(std::ostream& os, const Book& book);