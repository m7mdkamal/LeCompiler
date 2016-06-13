//
// Created by mohamed on 4/28/16.
//

#include <gtest/gtest.h>
#include "../include/lexer/LexicalAnalyser.h"
#include "../include/parser/Parser.h"
#include "../include/utils/IfStatement.h"
#include "../include/exception/ParserException.h"

class ParserTest : public testing::Test {
public:

    ParserTest() {
        lex = new LexicalAnalyser("");
        parser = new Parser(lex);
    }


    virtual void SetUp() {

    }

    ~ParserTest() {
        delete parser;
        delete lex;
    }

    Parser *parser;
    LexicalAnalyser *lex;
};


TEST_F(ParserTest , EmptyParsing){
    ASSERT_TRUE(parser->isFinished());
}

TEST_F(ParserTest , PrintStatement){
    lex->setSourceCode("print \" Hello World!! \" ;");
    Program pro = parser->parse();
    std::vector <Statement*> sts = pro.getStmts();
    ASSERT_EQ(sts[0]->toString(),"Print Statement");
}

TEST_F(ParserTest , ifStatement){
    lex->setSourceCode("if(a>b) print \" Hello World!! \" ;");
    Program pro = parser->parse();
    std::vector <Statement*> sts = pro.getStmts();
    ASSERT_EQ(sts[0]->toString(),"If Statement");

    ASSERT_EQ(dynamic_cast<IfStatement*>(sts[0])->getStatement()->toString(),"Print Statement");
}

TEST_F(ParserTest , ifStatementError){
    lex->setSourceCode("if(a>b print \" Hello World!! \" ;");
    try {
        parser->parse();
        FAIL();
    }catch (const ParserException& pe){
        SUCCEED();
    }
}
TEST_F(ParserTest , ifStatment){

}



