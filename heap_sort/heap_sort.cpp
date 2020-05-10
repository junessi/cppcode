#include <iostream>
#include <vector>
#include <cstdint>

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
    while (true)
    {
        swap(v, 0, n);
        sink(v, 0, n);
        n--;

        if (n == 0)
        {
            break;
        }
    }
}

int main(int argc, char** argv)
{
    std::vector<uint32_t> v{4, 9, 2, 10, 14, 1, 3, 5};
    sort(v);
    insert(v, 6u);
    for (const uint32_t i : v)
    {
        std::cout << i << " " << std::endl;
    }

    return 0;
}
