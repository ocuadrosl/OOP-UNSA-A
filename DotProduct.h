#ifndef DOTPRODUCT_H
#define DOTPRODUCT_H

#include <vector>

struct DotProduct
{
    int operator()(const std::vector<int>& a, const std::vector<int>& b)
    {
        int result = 0;
        for(unsigned i=0; i < a.size(); ++i)
        {
            result += a[i]*b[i];
        }
        return result;
    };
};



#endif // DOTPRODUCT_H
