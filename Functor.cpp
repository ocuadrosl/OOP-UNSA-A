#include "Functor.h"


void Functor::operator()(float &radius) const
{
    radius = Pi * std::pow(radius,2);
    //std::cout<<"Functor: "<<area<<std::endl;
    //return area;
}


