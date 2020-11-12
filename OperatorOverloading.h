#ifndef OPERATOROVERLOADING_H
#define OPERATOROVERLOADING_H

#include <vector>
#include <array>

class Vector
{
    std::vector<int> Data{0};

public:
    Vector()=delete;

    Vector(std::size_t size = 0){ Data = std::vector<int>(size, 0) ;}

    int& operator[] (const unsigned& index){ return Data[index]; }
    const int& operator[](const unsigned& index) const {return Data[index]; }

    int& Get(unsigned index){return Data[index];}

};

class Matrix
{
    std::vector<Vector> Data;
public:
    Matrix()=delete;

    Matrix(std::size_t rows, std::size_t cols)
    {
        Data = std::vector<Vector> (rows,  {cols} );
    }

    Vector& operator[](const unsigned& index) {return Data[index];}
    const Vector& operator[](const unsigned& index) const {return Data[index];}



};


#endif // OPERATOROVERLOADING_H
