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
    void lock()
    {
        std::thread::id defaultId;
        const std::thread::id currentThreadId = std::this_thread::get_id();
        
        if (m_ownerThreadId.compare_exchange_strong(defaultId, currentThreadId))
        {
            const uint32_t oldValue = m_count.fetch_add(1);
            std::cout << "lock(): oldVaue: " << oldValue << &std::endl;

            if (oldValue == 0)
            {
                std::mutex::lock();
            }
        }
        else if (defaultId != currentThreadId)
        {
            std::mutex::lock(); // lock and wait for the other thread that owns the mutex
            m_ownerThreadId = currentThreadId;
            m_count = 1;
        }
        else
        {
            // defaultId == currentThreadId: reentry of mutex owner thread
            m_count++;
        }
    }

    void unlock()
    {
        const uint32_t oldValue = m_count.fetch_sub(1);
        std::cout << "unlock(): oldVaue: " << oldValue << &std::endl;
        if (oldValue == 1)
        {
            m_ownerThreadId = std::thread::id{};
            std::mutex::unlock();
        }
    }

private:
    std::atomic<std::thread::id> m_ownerThreadId{}; // a default-constructed thread id is treated as an invalid thread id
    std::atomic<uint32_t> m_count{0};
};

}}

#endif
