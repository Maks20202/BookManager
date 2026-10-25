#pragma once
#include <string>
#include "BookList.hpp"

class Profile {
    std::string Username;
    std::string Bio;
    std::vector<BookList> Lists;

};
