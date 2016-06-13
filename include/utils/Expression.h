//
// Created by mohamed on 4/26/16.
//

#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H


#include "Identifier.h"
#include "../intermediate/InstructionSequence.h"

class Expression {
public:
    Expression(Identifier identifier);
private:
    Identifier identifier;

};


#endif //COMPILER_EXPRESSION_H
