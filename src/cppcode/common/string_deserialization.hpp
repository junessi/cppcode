#ifndef __CPPCODE_COMMON_STRING_DESERIALIZATION__
#define __CPPCODE_COMMON_STRING_DESERIALIZATION__

#include <iostream>
#include <cstdint>

namespace cppcode { namespace common {

std::vector<std::string> string_deserialize0(const std::string& str)
{
    std::vector<std::string> deStr;
    std::string tmpStr;

    size_t len = str.size();
    size_t pos = 0;
    while (pos < len)
    {
        if ((len - pos) >= 4)
        {
            std::string segLen = str.substr(pos, 4);
            size_t n = std::atoi(segLen.data());
            pos += 4;
            if (n == 9999)
            {
                tmpStr += str.substr(pos, 9998);
                pos += 9998;
            }
            else
            {
                tmpStr += str.substr(pos, n);
                deStr.push_back(std::move(tmpStr));
                tmpStr.clear();
                pos += n;
            }
        }
        else
        {
            // meet invalid data, abort deserializing string.
            break;
        }
    }

    return deStr;
}

std::vector<std::string> string_deserialize1(const std::string& str)
{
    std::vector<std::string> deStr;

    if (str.empty())
    {
        return deStr;
    }

    std::ostringstream oss;
    auto c = str.begin();
    while (1)
    {
        if (c != str.end())
        {
            if (*c == '|')
            {
                if ((c + 1) == str.end())
                {
                    break;
                }
                else if (*(c + 1) == '|')
                {
                    // skip char
                    oss << *c;
                    c++;
                }
                else
                {
                    // save string
                    deStr.push_back(oss.str());
                    oss.str(std::string());
                }
            }
            else
            {
                oss << *c;
            }

            c++;
        }
        else
        {
            break;
        }
    }

    deStr.push_back(oss.str());

    return deStr;
}

}}

#endif
