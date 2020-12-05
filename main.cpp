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
#include "Factorial.h"
#include "Fibonacci.h"
#include "BubbleSort.h"


#include <functional>
#include <algorithm>
#include <typeinfo>

#include "OperatorOverloading.h"
#include "ComplexNumber.h"
#include "Lucas.h"
#include "DotProduct.h"
#include "Matrix.h"


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



/*  hilo::Matrix<float> matrix{10,90000000};
    matrix[0][0] =  20;
    matrix[1][1] =  10;

    std::cout<<matrix.ComputeInnerSum()<<"\n";
    std::cout<<matrix.ComputeInnerSumThread()<<"\n";
*/


    hilo::Matrix<ComplexNumber> matrix{10,90000000};
    matrix[0][0] =  {20, 5};
    matrix[1][1] =  {5, -20};

    //std::cout<<matrix.ComputeInnerSum()<<"\n";
    std::cout<<matrix.ComputeInnerSumThread()<<"\n";
    std::cout<<matrix.ComputeInnerSumThreadV2()<<"\n";



/*
    DotProduct dp;
    std::cout<<dp({1,2,3}, {1,2,3})<<"\n";
*/

    /*
    std::cout<<Lucas<5>::Result<<std::endl;
    std::cout<<Lucas2(5)<<std::endl;
*/



/*

    ComplexNumber a{3, 4}, b{2, -5};

    std::cout << a*b;
*/


/*
    std::vector<float> data(6, 0);
    data[0] = -9;
    data[3] = -20.f;
    data[2] = -1;
    data[1] = 4;
    data[4] = 45;
    data[5] = 8;

    BubbleSort<std::vector<float>, 6>::Sort(data);
    //BubbleSortRegular<std::vector<float>, 5>(data);

    for(auto val: data)
    {

        std::cout<<val<<"\n";
    }
*/




    /*int fa = Factorial<10>::Result;
    int fi = Fibonacci<30>::Result;
    std::cout<<fi<<"\n";
*/


    //int f = Factorial<int>(3);
    //std::cout<<f<<"\n";



    /*oop::MyVector a{10}, b{10};

    a[4] = 6;
    b[3] = 10;

    std::vector<int> gravity(10, 0);
    std::vector<int> velocity(10, 1);

    int x = velocity.size();

    using  vectorInt = std::vector<int>;
    using  MyVector = oop::MyVector;

    //truco
    const auto& euclideanDistance = utils::EuclideanDistance<vectorInt, vectorInt, 10>;

    auto d = euclideanDistance(gravity, velocity);

    std::cout<<d<<"\n";
*/

    //utils::EuclideanDistance<vectorInt, vectorInt>(gravity, velocity, 10);
    //utils::EuclideanDistance<vector, vector>(a, b, 10);





    /*std::function< void(float&) > areaC_Func = AreaCircle;
    std::function< void(float&) > areaC_Obj  = Functor();

    TestFunctions(areaC_Func);
    */
    return 0;
}

