#pragma once

namespace cppcode {

    template <class T>
    void swap(std::vector<T>& v, size_t i, size_t j)
    {
        T t(v[i]);
        v[i] = v[j];
        v[j] = t;
    }

}
