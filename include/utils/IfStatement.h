//
// Created by mohamed on 4/26/16.
//

#ifndef COMPILER_IFSTATMENT_H
#define COMPILER_IFSTATMENT_H


#include "Expression.h"
#include "Statement.h"

class IfStatement : public Statement{
public:
    IfStatement(Expression* expression , Statement* statment );
    IfStatement(Expression* expression, Statement* statment, Statement* elseStatment);

    Statement *getStatement() const {
        return statement;
    }

    virtual std::string toString(){
        return "If Statement";
    }
private:
    Expression* expression;
    Statement* statement;
    Statement* elseStatement;
};


#endif //COMPILER_IFSTATMENT_H
