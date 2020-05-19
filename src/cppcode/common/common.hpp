#pragma once

namespace cppcode { namespace common {

    template <class T>
    void swap(std::vector<T>& v, size_t i, size_t j)
    {
        T t(v[i]);
        v[i] = v[j];
        v[j] = t;
    }

}}
