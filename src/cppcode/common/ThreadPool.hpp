#ifndef __THREADPOOL_HPP__
#define __THREADPOOL_HPP__

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <future>
#include <list>

namespace cppcode { namespace common {

class ThreadPool
{
public:
    ThreadPool(uint32_t numWorkers)
        : m_numWorkers{numWorkers}
        , m_running{false}
    {
        startWorkerThreads();
    }

    ~ThreadPool()
    {
        m_running = false;
        m_cv.notify_all();
        for (auto& t : m_workerThreads)
        {
            t.join();
        }
    }

    template <typename F, typename... Args>
    std::future<typename std::result_of<F(Args...)>::type>
    push(F&& f, Args&&... args)
    {
        using ReturnType = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<ReturnType()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));

        std::future<ReturnType> res = task->get_future();
        {
            std::lock_guard<std::mutex> lock{m_queueMutex};

            if (true == m_running)
            {
                m_tasks.emplace_back([task](){ (*task)(); });
            }
        }

        m_cv.notify_one();

        return res;
    }

private:
    void startWorkerThreads()
    {
        m_running = true;

        for (uint32_t i = 0; i < m_numWorkers; i++)
        {
            m_workerThreads.emplace_back([this](uint32_t workerId)
                                         {
                                             // std::cout << "worker " << workerId << " starts with thread "
                                             //           << std::this_thread::get_id() << std::endl;
                                             while (true)
                                             {
                                                 std::function<void()> task;

                                                 {
                                                     std::unique_lock<std::mutex> lock{m_queueMutex};

                                                     m_cv.wait(lock, [this](){ return this->m_running == false || !this->m_tasks.empty();});

                                                     if (m_running == false)
                                                     {
                                                         break;
                                                     }

                                                     if (false == m_tasks.empty())
                                                     {
                                                         task = std::move(m_tasks.front());
                                                         std::cout << "worker " << workerId << " got a task" << std::endl;
                                                         m_tasks.pop_front();
                                                     }
                                                 }

                                                 task();
                                             }
                                             // std::cout << "worker " << workerId << " ended" << std::endl;
                                         },
                                         i
            );
        }
    }

    uint32_t m_numWorkers;
    bool m_running;
    std::vector<std::thread> m_workerThreads;
    std::list<std::function<void()>> m_tasks;
    std::condition_variable m_cv;
    std::mutex m_queueMutex;
};

}}

#endif
