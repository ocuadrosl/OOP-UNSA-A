#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include <vector>
#include <memory>
#include "Queen.h"
#include "Pawn.h"

#include "Functor.h"
#include "MyVector.h"

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

    std::for_each(radius.begin(), radius.end(), func);
    //std::transform tarea

    for(auto a: radius)
    {
        std::cout<<a<<"\n";

    }


}


int main()
{

    MyVector a{5}, b{5}, c{5};

    a[1] = 6;
    b[1] = 4;

    std::cout << a[1] + b;


   /* std::function< void(float&) > areaC_Func = AreaCircle;
    std::function< void(float&) > areaC_Obj  = Functor();
    TestFunctions(areaC_Obj);
*/

    return 0;
}
