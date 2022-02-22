#include "../../inc/Lexical_Analysis/lexer.hpp"

Lexer::Lexer(std::string t) 
{
    cur_pos = Position(-1,0,-1);
    text = t;
    advance();
}

void Lexer::skip_ahead()
{
    std::string bad_chars = " \t\n\'\"";
    while ( bad_chars.find( cur_char ) != std::string::npos )
    {
        advance();
        if (cur_char == '\n')
        {
            cur_pos.newline();
        }
    }
}

bool Lexer::advance()
{
    cur_pos.advance();

    if (cur_pos.index() < text.size())
    {
        cur_char = text.at( cur_pos.index() );
        return true;
    }

    return false;
}

