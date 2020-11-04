#include "MyVector.h"

namespace oop
{
MyVector::MyVector(const std::size_t& size)
{

    Data = std::vector<int>(size, 0);
    std::cout<<"Vector of size "<<size<<" created\n";

}


MyVector operator+ (const MyVector& a, const int& b)
{
    //To-Do consistency test

    MyVector result{a.Data.size()};

    for(std::size_t i = 0; i < result.Data.size(); ++i)
    {
        result.Data[i]  = a.Data[i] + b;
    }

    return result;

}

MyVector operator+ (const int& b, const MyVector& a)
{
    //To-Do consistency test

    MyVector result{a.Data.size()};

    for(std::size_t i = 0; i < result.Data.size(); ++i)
    {
        result.Data[i]  = a.Data[i] + b;
    }

    return result;

}

MyVector operator+ (const MyVector& a, const MyVector& b)
{
    //To-Do consistency test

    MyVector result{a.Data.size()};

    for(std::size_t i = 0; i < result.Data.size(); ++i)
    {
        result.Data[i]  = b.Data[i] + a.Data[i];
    }

    return result;

}

MyVector operator-(const MyVector& a, const MyVector& b)
{
    //To-Do consistency test

    MyVector result{a.Data.size()};

    for(std::size_t i = 0; i < result.Data.size(); ++i)
    {
        result.Data[i]  = b.Data[i] - a.Data[i];
    }

    return result;

}

std::ostream& operator<<(std::ostream&  output, const MyVector& v)
{

    output<<"[";

    for(auto it = v.Data.begin(); it!= v.Data.end() - 1; ++it)
    {
        output<<*it<<", ";
    }

    output<< *v.Data.rbegin() <<"]\n";

    return output;

}

const int& MyVector::operator[](const unsigned& index) const
{
    return Data[index];
}

int& MyVector::operator[](const unsigned& index)
{
    return Data[index];
}


bool operator == (const MyVector& a, const MyVector& b)
{

    for(unsigned i=0; i< a.Data.size(); ++i)
    {
        if(a.Data[i] != b.Data[i])
        {
            return false;
        }

    }
        return true;

}


bool operator != (const MyVector& a, const MyVector& b)
{
    return !(a == b);
}

bool operator < (const MyVector& a, const MyVector& b)
{
    return std::accumulate(a.Data.begin(), a.Data.end(), 0) <
           std::accumulate(b.Data.begin(), b.Data.end(), 0);
}

bool operator > (const MyVector& a, const MyVector& b)
{
    return b < a;
}

bool operator <= (const MyVector& a, const MyVector& b)
{

    //return (a<b) || (a==b); //eder
    //return (a<b || a==b); //luis
    //return  !(a>b) || (a == b); //cesar
    return !(a > b);

}

bool operator >= (const MyVector& a, const MyVector& b)
{
    return !(a<b);
}

}





