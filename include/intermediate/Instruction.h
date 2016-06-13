//
// Created by mohamed on 4/30/16.
//

#ifndef COMPILER_INSTRUCTION_H
#define COMPILER_INSTRUCTION_H


#include <string>
#include <vector>
#include "Opcode.h"

class Instruction {
private:
    Opcode opcode;
    std::string stringOperand;
    int integerOperand;
public:

    Instruction(Opcode opcode) : opcode(opcode) { }

    Instruction(Opcode opcode, const std::string stringOperand) :
            opcode(opcode), stringOperand(stringOperand) { }


    Instruction(Opcode opcode, const int integerOperand) :
            opcode(opcode), integerOperand(integerOperand) { }


    Opcode getOpcode() const {
        return opcode;
    }


    const std::string &getStringOperand() const {
        return stringOperand;
    }

    const int &getIntegerOperand() const {
        return integerOperand;
    }


};


#endif //COMPILER_INSTRUCTION_H
