#ifndef __CPPCODE_RECURSIVE_MUTEX_HPP__
#define __CPPCODE_RECURSIVE_MUTEX_HPP__

#include <iostream>
#include <cstdint>
#include <mutex>
#include <thread>
#include <atomic>

namespace cppcode { namespace common {

class rmutex : public std::mutex
{
public:
    rmutex()
        : m_count(0)
    {}

    void lock()
    {
        std::thread::id currentThreadId = std::this_thread::get_id();
        
        if (m_ownerId == currentThreadId)
        {
            if (m_count == 0)
            {
                std::mutex::lock();
            }

            m_count++;
        }
        else
        {
            std::mutex::lock();
            m_ownerId = currentThreadId;
            m_count = 1;
        }
    }

    void unlock()
    {
        m_count--;
        if (m_count == 0)
        {
            std::mutex::unlock();
        }
    }

private:
    std::atomic<std::thread::id> m_ownerId;
    uint32_t m_count;
};

}}

#endif
