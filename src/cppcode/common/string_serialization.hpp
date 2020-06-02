#ifndef __CPPCODE_COMMON_STRING_SERIALIZATION__
#define __CPPCODE_COMMON_STRING_SERIALIZATION__

#include <iostream>
#include <sstream>
#include <cstdint>

namespace cppcode { namespace common {

std::string string_serialize0(const std::vector<std::string>& strings)
{
    std::ostringstream seStr;

    for (const auto& s : strings)
    {
        size_t len = s.size();
        size_t pos = 0;
        while (pos < len)
        {
            if ((len - pos) > 9998)
            {
                seStr << std::setw(4) << std::setfill('0') << std::to_string(9999);
                seStr << s.substr(pos, 9998);
                pos += 9998;
            }
            else
            {
                seStr << std::setw(4) << std::setfill('0') << std::to_string(len - pos);
                seStr << s.substr(pos, len - pos);
                break;
            }
        }
    }

    return seStr.str();
}

}}

#endif
