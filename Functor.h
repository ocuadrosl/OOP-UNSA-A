#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <cmath>
#include <iostream>

class Functor //function object
{
private:
    const float Pi{3.1415f};
public:

    void operator() (float& radius) const ;

    void printPi() const {std::cout<<Pi<<std::endl;};

};

#endif // FUNCTOR_H
