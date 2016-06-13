#include "../../include/lexer/LexicalAnalyser.h"

LexicalAnalyser::LexicalAnalyser(std::string source) {
    setSourceCode(source);
    keywords.insert("while");
    keywords.insert("print");
    keywords.insert("if");
    keywords.insert("else");
    keywords.insert("int");

}

LexicalAnalyser::~LexicalAnalyser() {
    sstream.clear();
}

bool LexicalAnalyser::next() {
    return sstream.peek()!=-1;
}

Token LexicalAnalyser::nextToken() {
    char ch;

    while (this->next()) {
        ch = (char) sstream.get();
//#ifndef DEBUG
//        std::cout << "-> " <<ch << std::endl;
//#endif
        if (ch == ' ' || ch == '\t')
            continue;
        else if (ch == '\n')
            lineNumber++;
        else if (ch == ';')
            return Token(Tag::SEMI);
        else if (ch == '{')
            return Token(Tag::CBO);
        else if (ch == '}')
            return Token(Tag::CBC);
        else if (ch == '(')
            return Token(Tag::RBO);
        else if (ch == ')')
            return Token(Tag::RBC);
        else if (ch == '+')
            return Token(Tag::PLUS);
        else if (ch == '-')
            return Token(Tag::MINUS);
        else if (ch == '*')
            return Token(Tag::MULT);
        else if (ch == '/')
            return Token(Tag::DIV);
        else if (ch == '=' && sstream.peek() != '=')
            return Token(Tag::ASSIGN);
        else if (ch == '=' || ch == '>' || ch == '<' || ch == '!')
            return nextOperatorToken(ch);
        else if (ch == '"')
            return this->nextStringToken();
        else if (isdigit(ch))
            return this->nextNumberToken(ch);
        else if (isalpha(ch))
            return this->nextAlphaToken(ch);
//            else if(ch)
        else
            break;
    }
    return Token(Tag::END);
}

Token LexicalAnalyser::nextNumberToken(char digit) {

    std::string v = "";
    v += digit;
    //std::cout << "DS " << v << std::endl;
    while (true) {
        char peek = (char) sstream.peek();
        if (isdigit(peek))
            digit = (char) sstream.get();
        else
            break;
        v += digit;
    }
    return Token(Tag::NUM, v);
}

Token LexicalAnalyser::nextStringToken() {
    std::string str = "";
    while (true) {
        char peek = (char) sstream.peek();
        if (peek == '"') {
            sstream.get();
            break;
        }
        str += sstream.get();
    }
    return Token(Tag::STRING, str);
}

Token LexicalAnalyser::nextAlphaToken(char ch) {

    std::string str = "";
    str += ch;
    while (true) {
        char peek = (char) sstream.peek();
        if (isalnum(peek)) {
            str += sstream.get();
        } else if (peek == '_') {
            str += sstream.get();
        } else {
            break;
        }
    }

    //The string found as keyword
    if (LexicalAnalyser::keywords.find(str) != LexicalAnalyser::keywords.end())
        return Token(Tag::KEYWORD, str);
    if(str == "and")
        return Token(Tag::AND);
    if(str == "or")
        return Token(Tag::OR);
    return Token(Tag::VAR, str);
}

Token LexicalAnalyser::nextOperatorToken(char ch) {
    std::string str = "";
    str += ch;
    char peek = (char) sstream.peek();
    if (peek == '=') {
        str += sstream.get();
    }
    return Token(Tag::OPERATOR, str);
}

void LexicalAnalyser::setSourceCode(std::string sourcecode) {
    this->sourceCode = sourcecode;
    sstream.str(sourceCode);
    lineNumber =1 ;
}












