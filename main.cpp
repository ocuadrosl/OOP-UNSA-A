#include <iostream>
#include "Vehicle.h"


void print(Vehicle vehicle) //vehicle is a copy
{
    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
}

int main()
{
    Vehicle car{2, "Blue"}; //this an object, ocupando memoria stack (ram)
    Vehicle moto;

    print(car);

    return 0;
}
