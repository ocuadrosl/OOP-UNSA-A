#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car: public Vehicle
{

public:
    Car();
    Car(uint16_t numberOfSits,
        uint16_t numberOfWheels,
        std::string color);

    uint16_t GetNumberOfSits() const ;
    std::string GetType() const;


};


struct Tico final: public Car
{
   bool autodestroy = true;
};




#endif // CAR_H
