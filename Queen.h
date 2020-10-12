#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "Piece.h"

class Queen : public Piece
{
private:

public:
    Queen()=delete;//{std::cout<<"Queen created\n";}
    Queen(std::string color): Piece(color){}

    std::string GetName() const {return "Queen";};
    bool GetStatus() const {return Status;};

    ~Queen(){std::cout<<"Queen destroyed\n";}
};

#endif // QUEEN_H
