//
// Created by mohamed on 4/26/16.
//

#ifndef COMPILER_PRINTSTATEMENT_H
#define COMPILER_PRINTSTATEMENT_H


#include "Statement.h"
#include "../intermediate/Opcode.h"
#include <string>
#include <iostream>
#include <string>

class PrintStatement : public Statement {
public:
    PrintStatement(std::string str);

    virtual std::string toString() {
        return "Print Statement";
    }

    void compile(InstructionSequence* seq) {

        seq->append(new Instruction(Opcode::PUSHS, str));
        seq->append(new Instruction(Opcode::PUSHS, std::string("\n")));
        seq->append(new Instruction(Opcode::OUTS));
    }

private:
    std::string str;
};


#endif //COMPILER_PRINTSTATEMENT_H
