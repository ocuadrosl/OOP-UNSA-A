#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <vector>

inline void BubbleSortRegular(std::vector<int> &data, unsigned i)
{
    for(unsigned j = 0; j < i; ++j) //loop principal
    {

        if(data[j] > data[i]) //condition
        {
            int aux = data[j];  //swap
            data[j] = data[i];
            data[i] = aux;

        }
    }

    if(i > 2)
    {
        BubbleSortRegular(data, i-1); //recursiva
    }

}



template <int Size>
struct BubbleSort
{
    static void Sort(std::vector<int>& data)
    {
        //loop -> swap
        BubbleSort<Size-1>::Sort(data);
    }
};


template <>
struct BubbleSort<1>
{
    static void Sort(std::vector<int>& data){}
};












#endif // BUBBLESORT_H
