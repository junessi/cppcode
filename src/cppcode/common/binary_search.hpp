#ifndef __BINARY_SEARCH_HPP__
#define __BINARY_SEARCH_HPP__

#include <iostream>
#include <cstdint>
#include <vector>

namespace cppcode { namespace common {

template <class T>
bool binary_search(const std::vector<T>& v, const T& t)
{
    int32_t n = static_cast<int32_t>(v.size());
    int32_t l = 0;
    int32_t r = (n == 0) ? 0 : n - 1;
    int32_t i = (l + r)/2;

    while (l <= r)
    {
        if (t < v[i])
        {
            r = i - 1;
        }
        else if (t > v[i])
        {
            l = i + 1;
        }
        else
        {
            return true;
        }

        i = (l + r)/2;
    }

    return false;
}

}}

#endif
