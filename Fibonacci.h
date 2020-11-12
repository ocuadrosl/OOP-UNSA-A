#ifndef FIBONACCI_H
#define FIBONACCI_H

template <auto Value>
struct Fibonacci
{
    enum { Result = Fibonacci<Value-1>::Result + Fibonacci<Value-2>::Result};
};

template <>
struct Fibonacci<1>
{
    enum { Result = 1};
};

template <>
struct Fibonacci<0>
{
    enum { Result = 0};
};


#endif // FIBONACCI_H
