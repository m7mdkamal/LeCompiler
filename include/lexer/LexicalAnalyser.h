/*
 * LexicalAnalyser.h
 *
 *  Created on: Apr 13, 2016
 *      Author: mohamed
 */

#ifndef LEXICAL_LEXICALANALYSER_H_
#define LEXICAL_LEXICALANALYSER_H_


#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include "Token.h"
#include "Tag.h"

class LexicalAnalyser {
public:
    LexicalAnalyser(std::string source);
    void setSourceCode(std::string source);
    bool next();
    virtual ~LexicalAnalyser();
    Token nextToken();

    int getLineNumber() const {
        return lineNumber;
    }

private:

    std::map<std::string, int> word;
    std::string sourceCode;
    std::stringstream sstream;
    std::set<std::string> keywords;
    Token nextNumberToken(char ch);
    Token nextStringToken();

    Token nextAlphaToken(char i);
    Token nextOperatorToken(char ch);

    int lineNumber;
};

#endif /* LEXICAL_LEXICALANALYSER_H_ */
