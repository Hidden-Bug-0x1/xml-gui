#include "../../inc/Lexical_Analysis/lexer.hpp"
#include "../utils/strutils.cpp"

Lexer::Lexer(std::string t) 
{
    cur_pos = Position(-1,0,-1);
    text = t;
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
            advance();
        }
    }
}
#include <iostream>
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

Token* Lexer::next_token()
{
    while (advance())
    {
        if(isalpha(cur_char))
        {
            return make_word();
        }
        // else if (isdigit(cur_char))
        // {
        //     return new Token(TOKEN::ERROR, "Cannot start with a digit: " + std::string(&cur_char), cur_pos.copy());
        // }
        else
        {
            switch( cur_char )
            {
                case '=':
                    return new Token(TOKEN::assign, std::string(&cur_char, 1), cur_pos.copy());
                case '<':
                    std::cout << "found a <" << std::endl;
                    return new Token(TOKEN::open, std::string(&cur_char, 1), cur_pos.copy());
                case '>':
                    std::cout << "found a >" << std::endl;
                    return new Token(TOKEN::close, std::string(&cur_char, 1), cur_pos.copy());
                case '/':
                    return new Token(TOKEN::slash, std::string(&cur_char, 1), cur_pos.copy());
                case ' ':
                    advance();
                    break;
                case '\t':
                    advance();
                    break;
                case '"':
                    return make_word_spaces();
                    break;
                case '\'':
                    advance();
                    break;
                case '\n':
                    cur_pos.newline();
                    advance();
                    break;
                default:
                    return new Token(TOKEN::ERROR, std::string(&cur_char, 1), cur_pos.copy());
            }
        }
    }
    return new Token(TOKEN::EORF, "", cur_pos.copy());
}

Token* Lexer::make_word_spaces()
{
    std::string word = "";

    Position* p = cur_pos.copy();

    while( isalnum(cur_char) || cur_char == ' ')
    {
        word += cur_char;
        if(!advance()) break;
    }

    word = trim(word);

    // skip_ahead();

    return new Token(TOKEN::string, word, p);
}

Token* Lexer::make_word()
{
    std::string word = "";

    Position* p = cur_pos.copy();

    while( isalnum(cur_char) )
    {
        word += cur_char;
        if(!advance()) break;
    }

    word = trim(word);

    // skip_ahead();

    return new Token(TOKEN::string, word, p);
}

std::vector<Token*>* Lexer::lex()
{
    std::vector<Token*>* tokens = new std::vector<Token*>();
    Token* token;
    while( (token = next_token())->token() != TOKEN::EORF)
    {
        tokens->push_back(token);
    }
    return tokens;
}