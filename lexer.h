#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include <utility>
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

class Lexer{
public:
    explicit Lexer(std::string input){
        m_input = std::move(input);
    }

    std::vector<Token> run(){
        std::vector<Token> tokens;
        int index = 0;
        while(index < m_input.length()){
            if(isalpha(m_input[index])){
                std::string word = {m_input[index]};
                index++;
                while((index < m_input.length()) && isalnum(m_input[index])){
                    word.push_back(m_input[index]);
                    index++;
                }
                index--;
                if(word == "return"){
                    tokens.push_back({TokenTypes::_return, "return"});
                }
                //can add other reserved namespaces here + variable names
            }
            else if(m_input[index] == '-' || isdigit(m_input[index])){
                std::string number = {m_input[index]};
                index++;
                while((index < m_input.length()) && isdigit(m_input[index])){
                    number.push_back(m_input[index]);
                    index++;
                }
                index--;
                tokens.push_back({TokenTypes::_int, number});
            }
            else if(m_input[index] == ';'){
                tokens.push_back({TokenTypes::_semi, ";"});
            }
            index++;
        }
        return tokens;
    }

private:
    std::string m_input;
};

