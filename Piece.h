#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

class Piece
{

protected:
    bool Status{};
    std::string Color{};

public:

    Piece()=delete;//{std::cout<<"Piece created\n";}
    Piece(std::string color):Color{color}{};


    virtual std::string GetName() const = 0;
    virtual bool GetStatus() const  = 0 ; // activa ->eliminada
    virtual uint16_t GetID() const = 0;
    virtual std::string GetColor() const =0;


     virtual ~Piece(){ std::cout<<"Piece destroyed\n";}

};

#endif // PIECE_H
