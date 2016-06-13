#include <iostream>
#include "../include/lexer/LexicalAnalyser.h"
#include "../include/parser/Parser.h"
#include <fstream>
#include <string>

#include <iostream>
#include <exception>
using namespace std;



int main() {

    cout << "Welcome to Torta Programming Language" << endl;
//    char buf[1024]; // hack, but fine for this
//    printf("%s\n", getcwd(buf, 1024));
    fstream fin("/home/mohamed/ClionProjects/compiler/sourcecode.txt", fstream::in);
    auto sourcecode = string("");

    while (!fin.eof()) {
        string s("");
        getline(fin, s);
        sourcecode.append(s).append("\n");
    }
    fin.close();

//    cout << fin.is_open() <<endl;
//	cout << sourcecode << endl;

    LexicalAnalyser lexical(sourcecode);
//    while (lexical.next()) {
//        Token token = lexical.nextToken();
//        cout << "< " << token.print() << " >" << endl;
//    }
//2+3;
    Parser parser(&lexical);
//
    Program p = parser.parse();

//    InstructionSequence *instructions = p.compile();;
//    for(Instruction *const & s : instructions->getInstructions()){
//        cout << s->getOpcode() << " " << s->getStringOperand() << endl;
//    }

//    while(parser.isFinished()){
//        parser.nextToken();
//    }


    return 0;
}