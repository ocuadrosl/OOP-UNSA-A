#include "Car.h"

Car::Car(): Vehicle(2, 4, "Blue")
{
    std::cout<<"Car default\n";
}

Car::Car(uint16_t numberOfSits,
         uint16_t numberOfWheels,
         std::string color):
    Vehicle(numberOfSits, numberOfWheels, color)

{
    std::cout<<"Car explicit\n";
}


uint16_t Car::GetNumberOfSits() const
{
    std::cout<<"Class Car\n";
    return NumberOfSits;
}

std::string Car::GetType() const
{
    return "Car\n";
}

