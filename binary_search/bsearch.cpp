#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

template <class T>
bool binary_search(const vector<T>& v, const T& t)
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

int main(int argc, char** argv)
{
    {
        vector<uint32_t> v{1, 5, 7, 9, 16, 22, 34};
        cout << binary_search(v, 34u) << endl;
    }

    {
        vector<uint32_t> v{1};
        cout << binary_search(v, 1u) << endl;
    }

    return 0;
}
