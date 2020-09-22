#include <iostream>
#include "Vehicle.h"
//por defecto c++ pasa por valor = crea una copia
//reference = alias = "address"
//paso por referencia permite modificar los valores

void print(const Vehicle& vehicle) //vehicle is a copy
{
    std::cout << vehicle.GetNumberOfSits() << std::endl;
    std::cout << vehicle.GetColor() << std::endl;
}

int main()
{

    /*
     Vehicle car{2, "Blue"}; //this an object, ocupando memoria stack (ram)
    Vehicle moto1;
    Vehicle moto2{car}; //copy, crear otro objeto
    Vehicle moto3;
    moto3 = moto1;  //asignacion, sobrecarga del operador igual
    {
        Vehicle car2;
    }

    print(moto1);
    */

    //raw pointers -> NO USAR NUNCA!!!!
    /*
    Vehicle  objCar; //stack y c++ lo destruye
    Vehicle* ptrCar = new Vehicle(); //por cada new un delete
    delete ptrCar;
    */

    std::unique_ptr ptrCar = std::make_unique<Vehicle>(); //sintaxis
    auto ptrCar2 = std::make_unique<Vehicle>(2, "Red"); //forma "muy sugerida"
    std::cout<<ptrCar2->GetColor()<<std::endl;

    //por norma NO SE CREA PUNTEROS!!!!!




    return 0;
}
