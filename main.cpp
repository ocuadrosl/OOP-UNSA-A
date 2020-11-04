#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include <vector>
#include <memory>
#include "Queen.h"
#include "Pawn.h"

#include "Functor.h"
#include "MyVector.h"
#include "Utils.h"


#include <functional>
#include <algorithm>


void AreaCircle(float &radius)
{

    //float area = 3.1415f * std::pow(radius,2);

    radius = 3.1415f * std::pow(radius,2);

    //std::cout<<"Function: "<<area<<std::endl;
    //return area;
}



void TestFunctions(const std::function<void(float&)>& func)
{
    std::vector<float> radius(10);

    for(auto it = radius.begin() ; it != radius.end(); ++it)
    {
        *it  = std::rand() % 100;
    }


    float rad = 5;
    const auto& area = [rad](float &val){ val = 3.1415 * std::pow(rad,2);};


    std::for_each(radius.begin(), radius.end(), area);
    //std::transform tarea

    for(auto a: radius)
    {
        std::cout<<a<<"\n";

    }


}

int main()
{

  /*  oop::MyVector a{5}, b{5}, c{5};

    a[1] = 3;
    b[1] = 9;
    auto  sum =  [a] (int x, int y) {  return x + y + a;  };
    std::cout<< sum(2,5) ;
    //std::cout << utils::EuclideanDistance(a,b) <<std::endl;
*/





    std::function< void(float&) > areaC_Func = AreaCircle;
    std::function< void(float&) > areaC_Obj  = Functor();


    TestFunctions(areaC_Func);


    return 0;
}
