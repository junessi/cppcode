#pragma once

#include <vector>
#include <cppcode/algo/sort/insert_sort.hpp>
#include <cppcode/algo/sort/selection_sort.hpp>

namespace cppcode { namespace algo { namespace sort {

enum class SORT_ALGO
{
    INSERT_SORT,
    SELECTION_SORT
};

template <typename T>
void sort(std::vector<T>& arr, SORT_ALGO algo)
{
    switch (algo)
    {
    case SORT_ALGO::INSERT_SORT:
        insert_sort(arr);
        break;
    case SORT_ALGO::SELECTION_SORT:
        selection_sort(arr);
        break;
    default:
        break;
    }
}

}}}