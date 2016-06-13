//
// Created by mohamed on 4/30/16.
//

#ifndef COMPILER_OPCODE_H
#define COMPILER_OPCODE_H

enum Opcode : char{
    PUSHS,
    PUSHI,
    LOAD,
    STORE,
    ADD,
    MUL,
    SUB,
    DIVI,
    CALL,
    RET,
    JMP,
    JMPGT,
    JMPGTE,
    JMPLT,
    JMPLTE,
    JMPNE,
    JMPEQ,
    HLT,
    IN,
    OUTS,
    OUTI,
    LABEL
};

#endif //COMPILER_OPCODE_H
