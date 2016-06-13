//
// Created by mohamed on 5/10/16.
//

#ifndef COMPILER_ASSIGNSTATEMENT_H
#define COMPILER_ASSIGNSTATEMENT_H


#include "Statement.h"
#include "Expression.h"
#include <string>

class AssignStatement : public Statement {

private:
    std::string name;
    Expression* expression;
public:
    AssignStatement(const std::string &name, Expression* expression){
        this->name = name;
        this->expression = expression;

    }
};


#endif //COMPILER_ASSIGNSTATEMENT_H
