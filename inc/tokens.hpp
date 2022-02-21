#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>

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
public:
    Token(TOKENS token, std::string value);
    ~Token();
    TOKENS token();
    std::string value();
};

#endif//TOKENS_HPP
