#include "Pawn.h"

uint16_t Pawn::Counter{1};

/*Pawn::Pawn()
{
   ID = Pawn::Counter++;
}
*/

Pawn::Pawn(std::string color): Piece(color)
{
    ID = Pawn::Counter++;
}


uint16_t Pawn::GetID() const
{
    return ID;
}
