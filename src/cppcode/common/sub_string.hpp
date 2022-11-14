#include <string>
#include <vector>
#include <iostream>

namespace cppcode { namespace common {

enum class SUB_STRING_ALGORITHM : uint8_t
{
    BRUTE_FORCE,
    KMP
};

int32_t sub_string_brute_force(const std::string& s, const std::string& needle);
int32_t sub_string_KMP(const std::string& s, const std::string& needle);

int32_t sub_string(const std::string& s, const std::string& needle, const SUB_STRING_ALGORITHM sub_string_algorithm = SUB_STRING_ALGORITHM::BRUTE_FORCE)
{
    switch (sub_string_algorithm)
    {
        case SUB_STRING_ALGORITHM::BRUTE_FORCE:
            break;
        case SUB_STRING_ALGORITHM::KMP:
            return sub_string_KMP(s, needle);
        default:
            break;
    }

    return sub_string_brute_force(s, needle);
}

int32_t sub_string_brute_force(const std::string& s, const std::string& needle)
{
    auto* p = s.data();
    for (size_t i = 0; i < (s.size() - needle.size() + 1); i++)
    {
        if (std::string_view{p++, needle.size()} == needle)
        {
            return i;
        }
    }

    return -1;
}

int32_t sub_string_KMP(const std::string& s, const std::string& needle)
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