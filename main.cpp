#include<iostream>
#include<fstream>
#include<sstream>
#include <vector>

#include "lexer.h"
#include "parser.h"

int main(int argc, char* argv[]) {
    if(argc != 2){
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::fstream file (argv[1]);
    std::stringstream content;
    content << file.rdbuf();
    std::cout << content.str() << std::endl;
    Lexer lexer = Lexer(content.str());
    std::vector<Token> tokens = lexer.run();

    //temporarily print out tokens to test
    for(Token t : tokens){
        std::cout << *t.value << std::endl;
    }

    Parser parser = Parser(tokens);
    ReturnNode tree = parser.run();

    //temporarily print out 'tree' to test
    if(tree.expr.has_value()){
        std::cout << *(tree.expr.value().expr).value << std::endl;
    }
    else{
        std::cout << "no return value" << std::endl;
    }
    return 0;
}

