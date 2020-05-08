#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

template <class T>
bool binary_search(const vector<T>& v, const T& t)
{
    size_t n = v.size();
    size_t l = 0;
    size_t r = (n == 0) ? 0 : n - 1;
    size_t i = (l + r)/2;

    while (l < r)
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
    vector<uint32_t> v{1, 5, 7, 9, 16, 22, 34};
    cout << binary_search(v, 34u) << endl;

    return 0;
}
