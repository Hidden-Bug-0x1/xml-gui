#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../inc/xml.hpp"

std::string tok2str(TOKEN tok)
{
    switch(tok)
    {
        case TOKEN::assign:
            return "assign";
        case TOKEN::close:
            return "close";
        case TOKEN::EORF:
            return "EORF";
        case TOKEN::ERROR:
            return "ERROR";
        case TOKEN::open:
            return "open";
        case TOKEN::slash:
            return "slash";
        case TOKEN::string:
            return "string";
    }
}

int main() {
    std::streampos size;
    
    std::ifstream xmltestfile;
    xmltestfile.open("/home/george/Desktop/xml-gui/test.xml", std::ios::in | std::ios::ate);

    if (!xmltestfile.is_open()) return 1;

    size = xmltestfile.tellg();
    char* data = new char[size];
    xmltestfile.seekg(std::ios::beg);
    xmltestfile.read(data, size);
    xmltestfile.close();

    xmltestfile.close();

    std::string text(data, size);
    std::cout << text << std::endl;

    Lexer* lexer = new Lexer(text);
    std::vector<Token*>* tokens = lexer->lex();

    // function to format the tokens into strings
    std::string (*format)(Token* token) = [](Token* token) {
        std::stringstream out;
        out << "[" << tok2str(token->token()) << ", '" << token->value() << "']";
        return out.str();
    };

    for(Token* token : *tokens)
    {
        std::cout << format(token) << std::endl;
    }

    return 0;
}