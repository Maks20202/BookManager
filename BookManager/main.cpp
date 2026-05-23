#include "Book.hpp"
#include <iostream>

int main() {
    Book book1("J.R.R Tolkien",
        "Lord of the Rings",
        1930,
        1000,
        10,
        false,
        Book::ReadingState::Complete);
    std::cout << book1 << std::endl;
}