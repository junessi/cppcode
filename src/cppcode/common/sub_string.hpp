#include <string>
#include <vector>
#include <iostream>

namespace cppcode { namespace common {

int32_t sub_string(const std::string& s, const std::string& needle)
{
    std::vector<uint32_t> lps(needle.size(), 0);

    int k = 0, i;
    for (i = 1; i < needle.size(); i++)
    {
        while (k > 0  && needle[k] != needle[i])
        {
            k = lps[k - 1];
        }

        if (needle[k] == needle[i])
        {
            lps[i] = ++k;
        }
    }

    k = 0;
    for (i = 0; i < s.size(); i++)
    {
        while (k > 0 && s[i] != needle[k])
        {
            k = lps[k - 1];
        }

        if (s[i] == needle[k])
        {
            k++;
        }

        if (k == needle.size())
        {
            return i - needle.size() + 1;
        }
    }

    return -1;
}

}}