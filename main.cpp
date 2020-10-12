#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include <vector>
#include <memory>
#include "Queen.h"
#include "Pawn.h"

//por defecto c++ pasa por valor = crea una copia
//reference = alias = "address"
//paso por referencia permite modificar los valores

void print(const Vehicle& vehicle) //vehicle is a copy
{
    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetNumberOfWheels() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;

}

int foo(int&& x) //r
{

    std::cout<<"r-value"<<std::endl;
    return ++x;
}

int foo(int& x) //l
{
    std::cout<<"l-value"<<std::endl;
    return ++x;
}


int main()
{

    std::unique_ptr<Piece> pawn1  = std::make_unique<Pawn>("White");
    std::unique_ptr<Piece> pawn2  = std::make_unique<Pawn>("");
    std::unique_ptr<Piece> pawn3  = std::make_unique<Pawn>("");
    std::unique_ptr<Piece> pawn4  = std::make_unique<Pawn>("White");


    std::cout<<pawn4->GetID()<<std::endl;
    std::cout<<pawn4->GetColor()<<std::endl;



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
