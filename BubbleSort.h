#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <vector>

template <typename VectorT,  unsigned size>
inline void BubbleSortRegular(VectorT &data)
{
    for(unsigned j = 0; j < size-1; ++j) //loop principal
    {
        if(data[j] > data[j+1]) //condition
        {
            auto aux = data[j];  //swap
            data[j] = data[j+1];
            data[j+1] = aux;
        }
    }
    if constexpr (size > 2) //compile
    {
        BubbleSortRegular<VectorT, size-1>(data); //recursiva
    }
}


template <typename VectorT, int i, int j>
inline static void Swap(VectorT& data)
{
    if(data[i] > data[j])
    {
        auto aux = data[j];
        data[j]  = data[i];
        data[i]  = aux;
    }
};


template <typename VectorT, unsigned j, unsigned Size>
struct BubbleSortLoop
{
    static void Loop(VectorT& data)
    {
        //swap
        Swap<VectorT, j, j+1>(data);
        //BubbleSortSwap<VectorT, j, j+1>::Swap(data);
        if constexpr (j+1 < Size) //compile
        {
            BubbleSortLoop<VectorT, j+1,  Size>::Loop(data);
        }
    }

};


template <typename VectorT, int Size>
struct BubbleSort
{
    static void Sort(VectorT& data)
    {
        BubbleSortLoop<VectorT, 0, Size-1>::Loop(data);
        if constexpr (Size > 2) //compile
        {
            BubbleSort<VectorT, Size-1>::Sort(data);
        }
    }
};


//template <typename VectorT>
//struct BubbleSort<VectorT, 1>
//{
//    static void Sort(VectorT&){}
//};

//template <typename VectorT>
//struct BubbleSortLoop<VectorT,0,0>
//{
//    static void Loop(VectorT&){}
//};









#endif // BUBBLESORT_H
