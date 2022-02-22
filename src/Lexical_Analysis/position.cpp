#include "../../inc/Lexical_Analysis/position.hpp"

Position::Position()
{
    m_col = 0;
    m_line = 0;
    m_index = -1;
}

Position::Position(long col, long line, long index=-1) 
: m_col(col), m_line(line), m_index(index)
{

}

void Position::advance()
{
    m_col++;
    m_index++;
}

void Position::newline()
{
    m_line++;
    m_col=-1;
}

long Position::index() 
{
    return m_index;
}

Position* Position::copy()
{
    return new Position(m_col, m_line, m_index);
}