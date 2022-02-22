#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
private:
    long m_col;
    long m_line;
    long m_index;   // accumulated position
public:
    Position(); //default constructor
    Position(long col, long line, long index=-1);
    void advance();     // increment col
    void newline();     // increment line and reset col
    long index();       // return m_index
    Position* copy();   // create a new Position with the same values
};

#endif//POSITION_HPP