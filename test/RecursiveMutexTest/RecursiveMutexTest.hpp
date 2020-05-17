#pragma once

#include <cppcode/recursive_mutex.hpp>

class MyTest
{
public:
    void f0()
    {
        std::lock_guard<cppcode::rmutex> lock(m_rmutex);
        std::cout << m_rmutex.rdepth() << std::endl;
        f1();
    }

    void f1()
    {
        std::lock_guard<cppcode::rmutex> lock(m_rmutex);
        std::cout << m_rmutex.rdepth() << std::endl;
    }
private:
    cppcode::rmutex m_rmutex;
};
