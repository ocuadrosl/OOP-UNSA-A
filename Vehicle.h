#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cinttypes>
#include <memory>

class Vehicle
{
private:

    uint16_t NumberOfSits{1};
    std::string Color{"White"};

public:

    void SetNumberOfSits(uint16_t numberOfSits);
    void SetColor(std::string color);

    uint16_t GetNumberOfSits() const;
    std::string GetColor() const; //metodos constantes

    Vehicle(); //default
    Vehicle(uint16_t numberOfSits, std::string color); //llama de form automatica al crear el objeto
    Vehicle(const Vehicle& otherVehicle);
    Vehicle& operator=(const Vehicle& otherVehicle);

    ~Vehicle(){std::cout<<"destroyed"<<std::endl;}


};


#endif // VEHICLE_H
