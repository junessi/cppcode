#include <iostream>
#include <vector>
#include <cstdint>

namespace heap {

    template <class T>
    void sort(std::vector<T>& v);

    template <class T>
    void swap(std::vector<T>& v, size_t i, size_t j)
    {
        T t(v[i]);
        v[i] = v[j];
        v[j] = t;
    }

    template <class T>
    void sink(std::vector<T>& v, size_t i, size_t n)
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

            swap(v, i, maxIndex);
            i = maxIndex;
        }
    }

    template <class T>
    size_t bubble(std::vector<T>& v, size_t i)
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
    void insert(std::vector<T>& v, T t)
    {
        v.push_back(std::move(t));
        sort(v);
    }

    template <class T>
    void erase(std::vector<T>& v, size_t i)
    {
        swap(v, i, v.size() - 1);
        v.pop_back();
        sort(v);
    }

    template <class T>
    int32_t bsearch(std::vector<T>& v, const T& t)
    {
        int32_t l = 0;
        int32_t r = static_cast<int32_t>(v.empty() ? 0 : v.size() - 1);

        while (l <= r)
        {
            int32_t i = (l + r)/2;

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
                return i;
            }
        }

        return -1;
    }

    template <class T>
    void build(std::vector<T>& v)
    {
        // 把[0, n/2 - 1]非叶子节点往下沉
        for (size_t i = v.size()/2 - 1;;i--)
        {
            sink(v, i, v.size());

            if (i == 0)
            {
                break;
            }
        }
    }

    template <class T>
    void sort(std::vector<T>& v)
    {
        build(v);

        size_t n = v.size() - 1;
        while (n > 0)
        {
            swap(v, 0, n);
            sink(v, 0, n);
            n--;
        }
    }

}

/*
int main(int argc, char** argv)
{
    std::vector<uint32_t> v{4, 9, 2, 10, 14, 1, 3, 5};
    heap::sort(v);
    heap::insert(v, 6u);
    for (const uint32_t i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int32_t i = heap::bsearch(v, 11u);
    std::cout << (i >= 0 ? "found" : "not found") << std::endl;

    i = heap::bsearch(v, 3u);
    heap::erase(v, i);
    for (const uint32_t i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
