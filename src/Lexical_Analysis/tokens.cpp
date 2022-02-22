#include "../../inc/Lexical_Analysis/tokens.hpp"

Token::Token(TOKENS token, std::string value, Position pos)
: m_token(token), m_value(value), m_pos(pos) 
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