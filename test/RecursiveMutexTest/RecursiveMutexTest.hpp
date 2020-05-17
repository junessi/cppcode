#pragma once

#include <cppcode/recursive_mutex.hpp>

namespace cppcode { namespace test {

class RecursiveMutexTest
{
public:
    void f0()
    {
        std::lock_guard<cppcode::rmutex> lock(m_rmutex);
        f1();
    }

    void f1()
    {
        std::lock_guard<cppcode::rmutex> lock(m_rmutex);
    }
private:
    cppcode::rmutex m_rmutex;
};

}}
