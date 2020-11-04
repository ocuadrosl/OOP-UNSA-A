#ifndef UTILS_H
#define UTILS_H

#include "MyVector.h"
#include <cmath>


namespace utils
{

inline double EuclideanDistance(const oop::MyVector& a, const oop::MyVector& b)
{

    double diffs=0;
    for( unsigned i=0 ; i< a.GetSize(); ++i)
    {
        diffs += std::pow(a[i] - b[i],2);
    }

    return std::sqrt(diffs);

}


}






#endif // UTILS_H
