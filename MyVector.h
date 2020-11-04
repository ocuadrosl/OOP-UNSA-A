#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>
#include <iostream>
#include <numeric>

namespace oop
{
class MyVector
{
private:

    std::vector<int> Data{0};


public:
    MyVector(const std::size_t& size=0);

    std::size_t GetSize() const { return Data.size(); }

    const int& operator[](const unsigned& index) const;

    int& operator[] (const unsigned& index);


    int& modify (unsigned index) {return Data[index]; }

    friend MyVector operator+ (const MyVector& a, const MyVector& b);
    friend MyVector operator- (const MyVector& a, const MyVector& b);
    friend MyVector operator+ (const MyVector& a, const int& b);
    friend MyVector operator+ (const int& b, const MyVector& a);

    friend  std::ostream& operator << (std::ostream & output, const MyVector& v);

    friend bool operator == (const MyVector& a, const MyVector& b);
    friend bool operator != (const MyVector& a, const MyVector& b);
    friend bool operator <  (const MyVector& a, const MyVector& b);
    friend bool operator >  (const MyVector& a, const MyVector& b);
    friend bool operator <= (const MyVector& a, const MyVector& b);
    friend bool operator >= (const MyVector& a, const MyVector& b);


};
};
#endif // MYVECTOR_H



