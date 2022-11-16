#pragma once

#include <vector>
#include <algorithm>

namespace cppcode { namespace algo { namespace sort {

template <typename T>
void selection_sort(std::vector<T>& arr)
{
    for (size_t i = 0; i < (arr.size() - 1); i++)
    {
        size_t idx = i;
        for (size_t j = (i + 1); j < arr.size(); j++)
        {
            if (arr[idx] > arr[j])
            {
                idx = j;
            }
        }
        std::swap(arr[idx], arr[i]);
    }
}

}}}