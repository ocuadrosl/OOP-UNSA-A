#ifndef FACTORIAL_H
#define FACTORIAL_H
/*
//Tipo de dato
template <typename Type>
Type Factorial(Type value)
{
    if(value==0)
    {
        return 1;
    }
    return  value * Factorial(value - 1);
}
*/

template <auto Value>
struct Factorial
{    
    enum {Result = Value * Factorial<Value-1>::Result};
};


template<>
struct Factorial<0> //por defecto
{
    enum{Result = 1};
};



#endif // FACTORIAL_H
