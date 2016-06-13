//
// Created by mohamed on 4/26/16.
//

#include <vector>
#include "../../include/parser/Parser.h"
#include "../../include/utils/PrintStatement.h"
#include "../../include/utils/IfStatement.h"
#include "../../include/utils/TestExpression.h"
#include "../../include/exception/ParserException.h"
#include "../../include/utils/Program.h"
#include "../../include/utils/AssignStatement.h"

Parser::Parser(LexicalAnalyser *lexicalAnalyser) : lexical(lexicalAnalyser), token(Token(Tag::ASSIGN)) {
}

void Parser::nextToken() {
    this->token = lexical->nextToken();
//#ifdef DEBUG
//    std::cout << "Current Token: " << token.print() << std::endl;
//#endif
}

bool Parser::isFinished() {
    return !this->lexical->next();
}

bool Parser::accept(Tag tag, bool getNext = true) {
    if (token.getTag() == tag) {
        if (getNext) nextToken();
        return true;
    }
    return false;
}

bool Parser::isNextKeywordEqual(std::string value) {
    return token.getTag() == Tag::KEYWORD && token.getValue() == value;
}

#include <typeinfo>

Program Parser::parse() {

    std::vector<Statement *> statements;
    while (!isFinished()) {

        statements.push_back(nextStatement());
//        cout << statements.size() << endl;
//        std::cout << "SD";
    }
    return Program(statements);

}

Statement *Parser::nextStatement() {
    nextToken();
    if (token.getTag() == Tag::KEYWORD) {
        std::string value = token.getValue();

        if (value == "if") {
            nextToken();
            if (!accept(Tag::RBO)) {
                throwError("`(` was expected");
            }
            Expression *expr = nextExpression();
            nextToken();
            if (!accept(Tag::RBC, false)) {
                throwError("`)` was expected");
            }
//            std::cout << "----> " << token.getTag() << std::endl;
            Statement *stat = nextStatement();
            if (isNextKeywordEqual("else")) {
                nextToken();
                Statement *elsestat = nextStatement();
                return new IfStatement(expr, stat, elsestat);
            } else {
//                std::cout << stat->toString() <<std::endl ;
                return new IfStatement(expr, stat);
            }
        } else if (value == "while") {

        } else if (value == "print") {
            nextToken();
            if (token.getTag() == Tag::STRING) {
                PrintStatement *printStatement = new PrintStatement(token.getValue());
                nextToken();
                accept(Tag::SEMI);
                return printStatement;
            } else {
                std::cout << "Print only available for strings";
            }

        } else {
            std::cout << "Error Keyword not handled: " << token.getValue() << std::endl;
        }

    } else {
        switch (token.getTag()) {
            case Tag::CBO : {
                accept(Tag::CBO, false);
                Statement *stmtBlock = nextStatement();
                nextToken();
                accept(Tag::CBC);
                return stmtBlock;
            }
            case Tag::VAR : {
                std::string var = token.getValue();
                accept(Tag::VAR);
                accept(Tag::ASSIGN);
                Expression *expr = nextExpression();
                return new AssignStatement(var, expr);
            }
            default:
                std::cout << "Error tag not handled: " << token.getTag() << std::endl;
        }
    }
//    nextToken();
}

Expression *Parser::nextExpression() {

    if (token.getTag() == Tag::VAR) {
        nextToken();
        if (token.getTag() == Tag::OPERATOR) {
            nextToken();
            if (token.getTag() == Tag::VAR) {
                return new TestExpression(Identifier(token.getValue()));
            }
        } else {

        }
    }

}


Expression *Parser::boolean() {
    Expression *expr = this->join();
    while (accept(Tag::OR, false)) {
        Token token = token;
        nextToken();
        expr = new Or(token, expr, join());
    }
    return expr;
}


Expression *Parser::join() {
    Expression *x = this->equality();
    while (accept(Tag::AND, false)) {
        Token token = token;
        nextToken();
        x = new And(token, x, equality());
    }
    return x;
}

Expression *Parser::equality() {
    Expression * x = rel();

    while (accept(Tag::EQ , false) || accept(Tag::NE , false) ) {
        Token token = token;
        nextToken();
        x = new Rel(token, x, rel());
    }
    return x;
}

Expression *Parser::rel() {
    Expression * x = expr();
    if(token.getTag() == Tag::OPERATOR) {
        return new Rel(token, x, expr());
    }
    return x;
}

Expression *Parser::expr() {
    Expression *x = term();
    while (accept(Tag::PLUS , false) || accept(Tag::MINUS , false) ) {
        Token token = token;
        nextToken();
        x = new Arith(token, x, term());
    }
    return x;
}

Expression *Parser::term() {
    Expression *x = unary();
    while (accept(Tag::MULT , false) || accept(Tag::DIV , false) ) {
        Token token = token;
        nextToken();
        x = new Arith(token, x, unary());
    }
    return x;
}

Expression *Parser::unary() {
    if(accept(Tag::MINUS , false)) {
        nextToken();
        return new Unary(Word.minus, unary());
    } else if(accept(Tag::NIG , false)) { // !
        Token token = token;
        nextToken();
        return new Not(token, unary());
    }
    return factor();
}

Expression *Parser::factor() {
    Expression * x = nullptr;
    switch (token.getTag()) {
        case Tag::RBO :
            nextToken();
            x = boolean();
            accept(Tag::RBC , false);
            return x;
        case Tag::NUM:
            x = new Constant(token.getValue(), Type.Int);
            nextToken();
            return x;
//        case Tag.REAL:
//            x = new Constant(lookAhead, Type.Float);
//            move();
//            return x;
        case Tag::TRUE:
            x = Constant.True;
            nextToken();
            return x;
        case Tag::FALSE:
            x = Constant.False;
            nextToken();
            return x;
        default:
            throwError("syntax error");
            return x;
        case Tag::VAR:
            std::string s = token.getValue();
            Id id = top.get(lookAhead);
            if (id == null) {
                throwError(token.getValue() + " undefined");
            }
            nextToken();
            return id;


    }
}


void Parser::throwError(std::string s) {
    s.append(" at line " + to_string(lexical->getLineNumber()));
    throw ParserException(s.c_str());
}








