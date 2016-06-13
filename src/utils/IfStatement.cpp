//
// Created by mohamed on 4/26/16.
//

#include "../../include/utils/IfStatement.h"

IfStatement::IfStatement(Expression *expression, Statement* statement) : expression(expression) , statement(statement) {

}

IfStatement::IfStatement(Expression* expression, Statement* statement, Statement* elseStatement)
        : expression(expression) {
    this->statement = statement;
    this->elseStatement = elseStatement;
}









