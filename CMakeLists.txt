cmake_minimum_required(VERSION 3.5)
project(compiler)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES include/utils/Program.h
        src/intermediate/Instruction.cpp
        src/intermediate/InstructionSequence.cpp
        include/intermediate/Opcode.h
        include/intermediate/Instruction.h
        include/intermediate/InstructionSequence.h
        src/utils/Program.cpp
        include/exception/ParserException.h
        src/main.cpp src/lexer/LexicalAnalyser.cpp
        include/lexer/LexicalAnalyser.h src/lexer/Token.cpp
        include/lexer/Token.h
        include/lexer/Tag.h
        src/parser/Parser.cpp
        include/parser/Parser.h
        src/utils/Statement.cpp
        include/utils/Statement.h
        src/utils/PrintStatement.cpp
        include/utils/PrintStatement.h
        include/utils/AssignStatement.h
        src/utils/AssignStatement.cpp
        src/utils/Expression.cpp
        include/utils/Expression.h
        src/utils/TestExpression.cpp
        include/utils/TestExpression.h
        src/utils/IfStatement.cpp
        include/utils/IfStatement.h
        src/utils/Identifier.cpp
        include/utils/Identifier.h)
add_executable(compiler ${SOURCE_FILES})
add_library(compiler_lib ${SOURCE_FILES})
add_subdirectory(lib/googletest)
add_subdirectory(tests)


