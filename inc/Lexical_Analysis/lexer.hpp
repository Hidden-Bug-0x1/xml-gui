#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include "./tokens.hpp"
#include "./position.hpp"

class Lexer {
private:
    Position cur_pos;   // current index of the lexer
    char cur_char;      // current character
    std::string text;   // data being lexed
public:
    Lexer(std::string t);
    ~Lexer();
    std::vector<Token*>* lex();   // lexes the input
    void skip_ahead();  // skip bad chars
    bool advance();     // advances the position
    Token* next_token(); // gets the next token
    Token* make_word();  // makes a word Token
    Token* make_word_spaces(); // makes a word that can contain spaces between letters and numbers
};

#endif//LEXER_HPP