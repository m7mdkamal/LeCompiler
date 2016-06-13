//
// Created by mohamed on 4/30/16.
//

#ifndef COMPILER_INSTRUCTIONSEQUENCE_H
#define COMPILER_INSTRUCTIONSEQUENCE_H


#include <vector>
#include <string>
#include "Instruction.h"

class InstructionSequence {
private:
    std::vector<Instruction*> instructions;
    int labelCounter = 0;

public:
    std::string createLineLabel(int line) {
        return "line_" + line;
    }

    std::string createGeneratedLabel() {
        return "generated_" + (labelCounter++);
    }

    void append(Instruction* instructions) {
        this->instructions.push_back(instructions);
    }


    const std::vector<Instruction *> &getInstructions() const {
        return instructions;
    }


};


#endif //COMPILER_INSTRUCTIONSEQUENCE_H
