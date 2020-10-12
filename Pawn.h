#ifndef PAWN_H
#define PAWN_H

#include <cinttypes>

#include "Piece.h"

class Pawn : public Piece
{
public:

    uint16_t ID;
    Pawn()=delete;
    Pawn(std::string color);

    std::string GetName() const {return "Pawn";};
    bool GetStatus() const {return Status;}; // activa ->eliminada
    std::string GetColor() const {return Color;}

    uint16_t GetID() const;

private:
    static uint16_t Counter; //declaro


};

#endif // PAWN_H


