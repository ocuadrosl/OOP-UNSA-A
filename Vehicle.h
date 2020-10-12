#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cinttypes>
#include <memory>

class Vehicle
{


protected:

    uint16_t NumberOfSits{1};
    uint16_t NumberOfWheels{1};
    std::string Color{"White"};


public:

    void SetNumberOfSits(uint16_t numberOfSits);
    void SetColor(std::string color);

    uint16_t GetNumberOfSits() const;
    uint16_t GetNumberOfWheels() const;
    std::string GetColor() const; //metodos constantes

    Vehicle(); //default

    Vehicle(uint16_t numberOfSits,
            uint16_t numberOfWheels,
            std::string color); //explicit

    Vehicle(const Vehicle& otherVehicle); //copy constructor L-value

    Vehicle& operator=(const Vehicle& otherVehicle);

    Vehicle(Vehicle&& otherVehicle); //rvalues <- move //R-value
    ~Vehicle(){ std::cout<<"vehicle destroyed\n";}


};


#endif // VEHICLE_H
