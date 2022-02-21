#include "../inc/tokens.hpp"

Token::Token(TOKENS token, std::string value)
: m_token(token), m_value(value) 
{
    // nothing to do here ...
}

TOKENS Token::token () 
{
    return m_token;
}
std::string Token::value ()
{
    return m_value;
}