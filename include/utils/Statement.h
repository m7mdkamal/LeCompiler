//
// Created by mohamed on 4/26/16.
//

#ifndef COMPILER_STATMENT_H
#define COMPILER_STATMENT_H

#include <iostream>
#include <string>
#include "../intermediate/InstructionSequence.h"

class Statement {

public:
    virtual std::string toString(){
       return "Statement";
    };
    virtual void compile(InstructionSequence* seq){}
};


#endif //COMPILER_STATMENT_H
