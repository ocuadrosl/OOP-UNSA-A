#ifndef LUCAS_H
#define LUCAS_H



constexpr long Lucas2(unsigned Value)
{
    if (Value==0)
    {
        return 2;
    }
    if  (Value ==1)
    {
        return 1;
    }

    return Lucas2(Value-1) + Lucas2(Value-2);
}



template <unsigned Value>
struct Lucas
{
    enum { Result = Lucas<Value-1>::Result  + Lucas<Value-2>::Result};

};

template <>
struct Lucas<0>
{
    enum {Result = 2};
};

template <>
struct Lucas<1>
{
    enum {Result = 1};
};






#endif // LUCAS_H
