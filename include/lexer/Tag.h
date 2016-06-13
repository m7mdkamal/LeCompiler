//
// Created by mohamed on 4/25/16.
//

#ifndef COMPILER_TAG_H
#define COMPILER_TAG_H


enum Tag : char {
    NUM,
    STRING,

    TRUE,
    FALSE,


    ASSIGN, // =
//    ISEQ, // ==
//    ISBT, // >
//    ISLT, // <
//    ISBE, // >=
//    ISLE, // <=
//    ISNQ, // !=

    CBC, // }  Curly brackets close
    CBO, // {  Curly brackets open
    RBC, // )  Round brackets
    RBO, // (
    SEMI, // ;

    PLUS, //10
    MINUS,
    MULT,
    DIV,
    KEYWORD, // 14
    VAR, //15
    OPERATOR, //16
    AND,
    OR,
    END
};


#endif //COMPILER_TAG_H
