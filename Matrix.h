#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <numeric>
#include <chrono>
#include <thread>
#include <future>

namespace hilo
{
template <typename DataType>
class Matrix //outer class
{

    using RowType = std::vector<DataType>;
    using MatrixType = std::vector<RowType>;

    MatrixType Data{};

    std::size_t Rows{0};
    std::size_t Columns{0};

public:
    Matrix();
    Matrix(const std::size_t& rows,  const std::size_t& columns);

    const RowType& operator[](unsigned rowIndex) const {return Data[rowIndex];}
    RowType& operator[](unsigned rowIndex) {return Data[rowIndex];}

    DataType ComputeInnerSum();
    DataType ComputeInnerSumThread();
    DataType ComputeInnerSumThreadV2();

    class Iterator; //promesa...

    Iterator Begin()
    {
        return Iterator{Data, 0};
    }

    Iterator End()
    {
        return Iterator{Data, Rows*Columns};
    }

    class Iterator //inner class
    {
    public:
        Iterator(MatrixType& data, unsigned index):
            Data{data},
            CurrentIndex{index}
        {};


        Iterator& operator++() //Next
        {
            ++CurrentIndex;
            return *this;
        }

        friend bool operator != (const Iterator& itA, const Iterator& itB)
        {
            return itA.CurrentIndex != itB.CurrentIndex; //no es optimo!!
        }

        DataType& operator*() //Set
        {
            unsigned row = CurrentIndex / Data[0].size();
            unsigned col = CurrentIndex % Data[0].size();
            return Data[row][col];
        }

        const DataType& operator*() const //Get
        {
            unsigned row = CurrentIndex / Data[0].size();
            unsigned col = CurrentIndex % Data[0].size();
            return Data[row][col];
        }



    private:
        unsigned CurrentIndex{};
        MatrixType& Data{};



    };





























};

template<typename DataType>
DataType Matrix<DataType>::ComputeInnerSumThreadV2()
{

    auto start = std::chrono::steady_clock::now();
    std::vector<std::shared_future<DataType>> rowSums(Rows);

    auto accumulate  = std::accumulate<typename RowType::const_iterator, DataType>; //function alias

    //suma filas
    for(unsigned rowIndex=0 ; rowIndex < Rows; ++rowIndex)
    {//scop
        rowSums[rowIndex] = std::async(accumulate,  Data[rowIndex].begin(), Data[rowIndex].end(), DataType{});

    }

    DataType sum{};
    for(auto rowRow: rowSums)
    {
        sum += rowRow.get();
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> seconds = end-start;
    std::cout << "time: " << seconds.count() << "s\n";

    return sum;



}


template<typename DataType>
DataType Matrix<DataType>::ComputeInnerSumThread()
{
    auto start = std::chrono::steady_clock::now();

    auto rowSum = [this](unsigned rowIndex, DataType& sum)
    {
        sum = std::accumulate(Data[rowIndex].begin(), Data[rowIndex].end(), DataType{} );
    };


    std::vector<std::thread> threads;
    std::vector<DataType> rowSums(Rows, DataType{});

    for(unsigned i=0; i< Rows; ++i)
    {
       threads.emplace_back( std::thread (rowSum, i, std::ref(rowSums[i])));
    }

    for(auto& thread: threads)
    {
        thread.join();
    }
    //todo se detiene
    //esperar aqui
    DataType totalSum = std::accumulate( rowSums.begin(), rowSums.end(), DataType{} );

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> seconds = end-start;
    std::cout << "time: " << seconds.count() << "s\n";

    return totalSum;



}

template<typename DataType>
DataType Matrix<DataType>::ComputeInnerSum()
{

    auto start = std::chrono::steady_clock::now();

    DataType sum{};
    for(auto row : Data)
    {
        sum += std::accumulate(row.begin(), row.end(), DataType{});
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> seconds = end-start;
    std::cout << "time: " << seconds.count() << "s\n";

    return sum;

}


template <typename DataType>
Matrix<DataType>::Matrix():
    Data { MatrixType(0, RowType(0, DataType{} )) }
{

}

template <typename DataType>
Matrix<DataType>::Matrix(const std::size_t& rows,  const std::size_t& columns):
    Data{ MatrixType ( rows, RowType(columns, DataType{} ))},
    Rows{rows},
    Columns{columns}
{
    std::cout<<"explicit"<<"\n";
}


}








#endif // MATRIX_H
