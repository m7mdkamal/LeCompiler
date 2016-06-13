//
// Created by mohamed on 4/26/16.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include "../lexer/LexicalAnalyser.h"
#include "../utils/Statement.h"
#include "../utils/Expression.h"
#include "../utils/Program.h"
#include <string>
#include <vector>
class Parser {
public:
    Parser(LexicalAnalyser* lexicalAnalyser);
    bool isFinished();
    Program parse();
    ~Parser(){
    }

private:
    LexicalAnalyser* lexical;
    Token token;

    Statement* nextStatement();
    Expression * nextExpression();
    bool isNextKeywordEqual(std::string value);
    bool accept(Tag tag, bool next);
    void nextToken();
    void throwError(std::string s);
    Expression * boolean();
    Expression * join();
    Expression * equality();
    Expression * rel();
    Expression * expr();
    Expression * term();
    Expression * unary();
    Expression * factor();


};


#endif //COMPILER_PARSER_H
