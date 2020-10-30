#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>
#include <iostream>

class MyVector
{
private:

    std::vector<int> Data{0};


public:
    MyVector(const std::size_t& size=0);


    const int& operator[](const unsigned& index) const;
    int& operator[] (const unsigned& index);


    int& modify (unsigned index){return Data[index]; }

    friend MyVector operator+ (const MyVector& a, const MyVector& b);
    friend MyVector operator- (const MyVector& a, const MyVector& b);
    friend MyVector operator+ (const MyVector& a, const int& b);
    friend MyVector operator+ (const int& b, const MyVector& a);

    friend  std::ostream& operator<<(std::ostream & output, const MyVector& v);

};



#endif // MYVECTOR_H



