//
// Created by mohamed on 4/25/16.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <string>
#include "Tag.h"


class Token {
public:
    Token(Tag tag);
    Token(Tag tag , std::string value);
    Tag getTag();
    std::string getValue();
    std::string print();
    ~Token(){


    }
private:
    Tag tag;
    std::string value;
};


#endif //COMPILER_TOKEN_H
