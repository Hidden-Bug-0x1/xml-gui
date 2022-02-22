#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "./position.hpp"

typedef enum {
    assign,     // =
    string,     // ex: 123, Bob, Jane
    open,       // <
    close,      // >
    slash,      // /
    EORF,       // the end of readable file
    ERROR,      // indicates that there is an error
} TOKEN;

class Token {
private:
    TOKEN m_token;
    std::string m_value;
    Position* m_pos;
public:
    Token(TOKEN token, std::string value, Position* pos);
    ~Token();
    TOKEN token();
    std::string value();
};

#endif//TOKEN_HPP
