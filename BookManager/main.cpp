#include "Book.hpp"
#include "BookList.hpp"
#include <iostream>

int main() {
    Book book1("J.R.R Tolkien","Lord of the Rings",1931,1000);
    Book book2("Aloppy", "flops", 1930, 10000);
    Book book3("Crimson Horizon", "Emily Carter", 2015, 380);
    Book book4("Echoes of Tomorrow", "Michael Reed", 2022, 610);
    Book book5("Fallen Empire", "Sophia Blake", 2011, 740);
    Book book6("Neon Dreams", "Ryan Cooper", 2019, 295);
    Book book7("The Last Voyage", "Olivia Turner", 2008, 560);
    Book book8("Digital Abyss", "Nathan Brooks", 2021, 470);
    Book book9("Whispers in Winter", "Grace Mitchell", 2016, 330);
    Book book10("Quantum Divide", "Liam Foster", 2024, 690);

    std::cout << book1 << std::endl;
    book1.addRating(7);
    book1.addRating(6);
    std::cout << book1 << std::endl;

    BookList books("Liked");
    books.addBook(book1);
    books.addBook(book2);
    books.addBook(book3);
    books.addBook(book4);
    books.addBook(book5);
    books.addBook(book6);
    books.addBook(book7);
    std::cout << books << std::endl;

}