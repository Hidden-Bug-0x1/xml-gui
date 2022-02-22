#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>
#include "./position.hpp"

typedef enum {
    assign,     // =
    string,     // ex: 123, Bob, Jane
    open,       // <
    close,      // >
    slash,      // /
} TOKENS;

class Token {
private:
    TOKENS m_token;
    std::string m_value;
    Position m_pos;
public:
    Token(TOKENS token, std::string value, Position pos);
    ~Token();
    TOKENS token();
    std::string value();
};

#endif//TOKENS_HPP
