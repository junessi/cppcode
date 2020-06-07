#pragma once

#include <cppcode/common/recursive_mutex.hpp>

namespace cppcode { namespace test {

class RecursiveMutexTest
{
public:
    void f0()
    {
        std::lock_guard<cppcode::common::rmutex> lock(m_rmutex);
        f1();
    }

    void f1()
    {
        std::lock_guard<cppcode::common::rmutex> lock(m_rmutex);
    }
private:
    cppcode::common::rmutex m_rmutex;
};

}}
