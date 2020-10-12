#include "Vehicle.h"

Vehicle::Vehicle(uint16_t numberOfSits,
                 uint16_t numberOfWheels,
                 std::string color) :
    NumberOfSits{numberOfSits},
    NumberOfWheels{numberOfWheels},
    Color{color}

{
    std::cout<<"Vehicle Created Explicit"<<std::endl;
}



Vehicle::Vehicle()
{
 std::cout<<"Vehicle Created Default"<<std::endl;

}


Vehicle::Vehicle(const Vehicle& otherVehicle):
    NumberOfSits{otherVehicle.NumberOfSits},
    Color{otherVehicle.Color}
{
    std::cout<<"Copy"<<std::endl;
}

Vehicle::Vehicle(Vehicle&& otherVehicle):
    NumberOfSits{otherVehicle.NumberOfSits},
    Color{otherVehicle.Color}
{
    std::cout<<"Move"<<std::endl;
}

void Vehicle::SetNumberOfSits(uint16_t numberOfSits)
{

    if(numberOfSits > 10)
    {
        std::cerr<<"Number of sits must be lower than 10"<<std::endl;
        return;
    }

    this->NumberOfSits = numberOfSits;

}

uint16_t Vehicle::GetNumberOfSits() const
{
    return NumberOfSits;
}

void Vehicle::SetColor(std::string color)
{
    this->Color  = color;
}
std::string Vehicle::GetColor() const
{
    return Color;
}

Vehicle& Vehicle::operator=(const Vehicle&)
{
    std::puts("Operator =");
}

uint16_t Vehicle::GetNumberOfWheels() const
{
    return NumberOfWheels;
}







