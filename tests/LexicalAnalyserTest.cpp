//
// Created by mohamed on 4/27/16.
//

#include <gtest/gtest.h>

#include "../include/lexer/LexicalAnalyser.h"

class LexicalAnalyserTest : public testing::Test {
public:

    LexicalAnalyserTest() {
        lex = new LexicalAnalyser("");
    }


    virtual void SetUp() {

    }

    ~LexicalAnalyserTest() {
        delete lex;
    }

    LexicalAnalyser *lex;

    bool acceptTag(Tag tag) {
        return tag == lex->nextToken().getTag();
    }

    bool acceptKeyword(std::string value) {
        Token token = lex->nextToken();
        return Tag::KEYWORD == token.getTag() && value == token.getValue();
    }
};

TEST_F(LexicalAnalyserTest, isEmpty) {
    EXPECT_FALSE(lex->next());
    EXPECT_FALSE(lex->next());
}

TEST_F(LexicalAnalyserTest, printStatement) {

    lex->setSourceCode("print \" Hello World!! \" ;");

    EXPECT_TRUE(acceptKeyword("print"));
    EXPECT_TRUE(acceptTag(Tag::STRING));
    EXPECT_TRUE(acceptTag(Tag::SEMI));
    EXPECT_FALSE(lex->next());

}

TEST_F(LexicalAnalyserTest, assignOperator ){
    lex->setSourceCode("int ifif=4;");

    EXPECT_TRUE(acceptKeyword("int"));
    EXPECT_TRUE(acceptTag(Tag::VAR));
    EXPECT_TRUE(acceptTag(Tag::ASSIGN));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(lex->next());
    EXPECT_TRUE(acceptTag(Tag::SEMI));
    EXPECT_FALSE(lex->next());
}

TEST_F(LexicalAnalyserTest, whileStatement){
    lex->setSourceCode("while(x>0)print \"Hello\";");

    EXPECT_TRUE(acceptKeyword("while"));
    EXPECT_TRUE(acceptTag(Tag::RBO));
    EXPECT_TRUE(acceptTag(Tag::VAR));
    EXPECT_TRUE(acceptTag(Tag::OPERATOR));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(acceptTag(Tag::RBC));
    EXPECT_TRUE(lex->next());
    EXPECT_TRUE(acceptKeyword("print"));
    EXPECT_TRUE(acceptTag(Tag::STRING));
    EXPECT_TRUE(acceptTag(Tag::SEMI));
    EXPECT_FALSE(lex->next());
    EXPECT_FALSE(lex->next());
}

TEST_F(LexicalAnalyserTest, ifStatement){
    lex->setSourceCode("if(x>0)print \"Hello\";");

    EXPECT_TRUE(acceptKeyword("if"));
    EXPECT_TRUE(acceptTag(Tag::RBO));
    EXPECT_TRUE(acceptTag(Tag::VAR));
    EXPECT_TRUE(acceptTag(Tag::OPERATOR));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(acceptTag(Tag::RBC));
    EXPECT_TRUE(lex->next());
    EXPECT_TRUE(acceptKeyword("print"));
    EXPECT_TRUE(acceptTag(Tag::STRING));
    EXPECT_TRUE(acceptTag(Tag::SEMI));
    EXPECT_FALSE(lex->next());
    EXPECT_FALSE(lex->next());
}

TEST_F(LexicalAnalyserTest, statement){
    lex->setSourceCode("x = 4 + 3 * 2 - 3;");

    EXPECT_TRUE(acceptTag(Tag::VAR));
    EXPECT_TRUE(acceptTag(Tag::ASSIGN));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(acceptTag(Tag::PLUS));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(acceptTag(Tag::MULT));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(acceptTag(Tag::MINUS));
    EXPECT_TRUE(acceptTag(Tag::NUM));
    EXPECT_TRUE(acceptTag(Tag::SEMI));
    EXPECT_FALSE(lex->next());
    EXPECT_FALSE(lex->next());
}


