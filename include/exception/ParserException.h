//
// Created by mohamed on 4/28/16.
//

#ifndef COMPILER_PARSEREXCEPTION_H
#define COMPILER_PARSEREXCEPTION_H
#include <iostream>
#include <exception>
using namespace std;

class ParserException : public exception
{
    const char* error;
public:
    ParserException(const char* str){
        error = str;
    }

    const char * what () const throw ()
    {
        return error ;
    }
};

#endif //COMPILER_PARSEREXCEPTION_H
