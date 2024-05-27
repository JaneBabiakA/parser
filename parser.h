#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
#include <utility>
#include <vector>
#include<optional>

struct IntegerNode{
    Token expr;
};

struct ReturnNode{
    std::optional<IntegerNode> expr;
};

class Parser{
public:
    explicit Parser(std::vector<Token> tokens){
        m_tokens = std::move(tokens);
    }

    ReturnNode run(){
        ReturnNode returnNode;
        for(int index = 0; index < m_tokens.size(); index++){
            if((m_tokens[index].type == TokenTypes::_return) && (index + 1 < m_tokens.size()) && (m_tokens[index + 1].type != TokenTypes::_semi)){
                returnNode.expr = IntegerNode({m_tokens.at(index + 1)});
            }
        }
        return returnNode;
    }

private:
    std::vector<Token> m_tokens;
};
