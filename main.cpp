#include<iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include<optional>

enum class TokenTypes{
    _return,
    _int,
    _semi
};

struct Token{
    TokenTypes type;
    std::optional<std::string> value {};
};

std::vector<Token> lexer(std::string content){
    std::vector<Token> tokens;
    int index = 0;
    while(index < content.length()){
        if(isalpha(content[index])){
            std::string word = {content[index]};
            index++;
            while((index < content.length()) && isalnum(content[index])){
                word.push_back(content[index]);
                index++;
            }
            index--;
            if(word == "return"){
                tokens.push_back({TokenTypes::_return, "return"});
            }
            //can add other reserved namespaces here + variable names
        }
        else if(content[index] == '-' || isdigit(content[index])){
            std::string number = {content[index]};
            index++;
            while((index < content.length()) && isdigit(content[index])){
                number.push_back(content[index]);
                index++;
            }
            index--;
            tokens.push_back({TokenTypes::_int, number});
        }
        else if(content[index] == ';'){
            tokens.push_back({TokenTypes::_semi, ";"});
        }
        index++;
    }
    for(Token t : tokens){
        std::cout << *t.value << std::endl;
    }
    return {};
}

int main(int argc, char* argv[]) {
    if(argc != 2){
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::fstream file (argv[1]);
    std::stringstream content;
    content << file.rdbuf();
    std::cout << content.str() << std::endl;
    lexer(content.str());
    return 0;
}

