//
// Created by mohamed on 4/25/16.
//

#include "../../include/lexer/Token.h"

Token::Token(Tag tag) {
    this->tag = tag;
    this->value = "";
}

Token::Token(Tag tag, std::string value) {
    this->tag = tag;
    this->value = value;
}

std::string Token::print() {
    Tag t = getTag();
    std::string str = std::to_string(t) +" " + getValue() ;
    return str;
}

Tag Token::getTag() {
    return tag;
}

std::string Token::getValue() {
    return value;
}









