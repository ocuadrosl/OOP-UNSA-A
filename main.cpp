#include <iostream>
#include "Vehicle.h"
#include <vector>
#include <memory>

//por defecto c++ pasa por valor = crea una copia
//reference = alias = "address"
//paso por referencia permite modificar los valores

void print(const Vehicle& vehicle) //vehicle is a copy
{
    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
}

void printSimple(Vehicle vehicle) //vehicle is a copy
{
    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
}



void foo(int&& x)
{
    x++;
    std::cout<<x<<std::endl;
}
void foo(int& x)
{
    x++;
    std::cout<<x<<std::endl;
}



int main()
{


    Vehicle car;
    printSimple( std::move(car) );//simule una referencia



   /*

    //verbosity ----
    std::unique_ptr<Vehicle> Car = std::make_unique<Vehicle>(1, "Red");
    //auto carPtr1 = std::make_unique<Vehicle>(); //auto C++ defina el tipo de dato
    //el puntero Car (stack) tiene la direcicon de un objeto tipo Vehicle -> heap

    auto carPtr2 = std::make_unique<Vehicle>(); //no memoria en la heap
*/

/*
    Vehicle *carRaw1 =  new Vehicle(4, "Red");
    std::cout<<carRaw1->GetColor()<<std::endl;

    Vehicle *carRaw2 =  nullptr;
    carRaw2 = carRaw1;
    auto carRaw3 = carRaw2;

    carRaw3->SetColor("Blue");

    std::cout<<carRaw1->GetColor()<<std::endl;

    //print(*carPtr);
*/


    //por norma NO SE CREA PUNTEROS!!!!!


    return 0;
}
