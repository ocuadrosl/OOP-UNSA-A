#ifndef UTILS_H
#define UTILS_H

#include "MyVector.h"
#include <cmath>
#include <functional>





namespace utils
{

template <typename VectorT1, typename VectorT2, unsigned size>
inline double EuclideanDistance(const VectorT1& a, const VectorT2& b)
{
    double diffs=0;
    for(unsigned i=0 ; i< size; ++i)
    {
        diffs += std::pow(static_cast<double>(a[i] ) - static_cast<double>(b[i]) , 2);
    }

    return std::sqrt(diffs);
}



void foo(const std::function<double(int, int)>& lambda)
{
    std::cout<<lambda(1,2)<<std::endl;
}

inline double EuclideanDistanceWierd(const oop::MyVector& a, const oop::MyVector& b)
{
    int exp = 20;
    auto diffPow = [exp](const auto& a, const auto& b) mutable //no puedo modificar capturas de forma temporal
                        {
                            exp = 2;
                            return std::pow(a-b, exp);
                        }; //funciones sin nombre, por valor => copias!!!

//    foo(diffPow);
    double diffs=0;
    for(unsigned i=0 ; i< a.size(); ++i)
    {
        diffs += diffPow(a[i], b[i]);
    }

    //std::cout<<exp<<"\n";
    return std::sqrt(diffs);

}






}






#endif // UTILS_H
