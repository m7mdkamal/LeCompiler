include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(compilerTests LexicalAnalyserTest.cpp ParserTest.cpp)


target_link_libraries(compilerTests gtest gtest_main)
target_link_libraries(compilerTests compiler_lib)
