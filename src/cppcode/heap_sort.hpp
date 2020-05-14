#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <cppcode/common.hpp>

namespace cppcode {

    template <class T>
    void heap_sort(std::vector<T>& v);

    template <class T>
    void heap_sink(std::vector<T>& v, size_t i, size_t n)
    {
        while (i < n)
        {
            size_t l = 2*i + 1;
            size_t r = 2*i + 2;
            size_t maxIndex = i;
            if ((l < n) && (v[maxIndex] < v[l]))
            {
                maxIndex = l;
            }

            if ((r < n) && (v[maxIndex] < v[r]))
            {
                maxIndex = r;
            }

            if (maxIndex == i)
            {
                break;
            }

            cppcode::swap(v, i, maxIndex);
            i = maxIndex;
        }
    }

    template <class T>
    size_t heap_bubble(std::vector<T>& v, size_t i)
    {
        while (i > 0)
        {
            size_t p = (i - 1)/2; // parent
            if (v[p] > v[i])
            {
                swap(v, i, p);
            }

            i = p;
        }

        return i;
    }

    template <class T>
    void heap_insert(std::vector<T>& v, T t)
    {
        v.push_back(std::move(t));
        heap_sort(v);
    }

    template <class T>
    void heap_erase(std::vector<T>& v, size_t i)
    {
        swap(v, i, v.size() - 1);
        v.pop_back();
        heap_sort(v);
    }

    template <class T>
    void heap_build(std::vector<T>& v)
    {
        // 把[0, n/2 - 1]非叶子节点往下沉
        for (size_t i = v.size()/2 - 1;;i--)
        {
            heap_sink(v, i, v.size());

            if (i == 0)
            {
                break;
            }
        }
    }

    template <class T>
    void heap_sort(std::vector<T>& v)
    {
        heap_build(v);

        size_t n = v.size() - 1;
        while (n > 0)
        {
            swap(v, 0, n);
            heap_sink(v, 0, n);
            n--;
        }
    }

}
