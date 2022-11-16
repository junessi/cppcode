#pragma once

#include <vector>
#include <algorithm>

namespace cppcode { namespace algo { namespace sort {

template <typename T>
void insert_sort(std::vector<T>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        for (size_t j = i; j > 0 && (arr[j] < arr[j - 1]); j--)
        {
            std::swap(arr[j], arr[j -  1]);
        }
    }
}

}}}