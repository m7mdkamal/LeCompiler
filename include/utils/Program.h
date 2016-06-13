//
// Created by mohamed on 4/30/16.
//

#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include <vector>
#include "Statement.h"

class Program {
private:
    std::vector<Statement *> stmts;
public:

    Program(const std::vector<Statement *> &stmts) : stmts(stmts) { }

    const std::vector<Statement *> &getStmts() const {
        return stmts;
    }

    void setStmts(const std::vector<Statement *> &stmts) {
        Program::stmts = stmts;
    }

    InstructionSequence* compile() {
        InstructionSequence *seq = new InstructionSequence();
        for (Statement *& stmt : stmts) {
            stmt->compile(seq);
        }
        return seq;
    }
};


#endif //COMPILER_PROGRAM_H
