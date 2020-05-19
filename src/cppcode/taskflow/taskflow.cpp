#include <cppcode/taskflow/taskflow.hpp>
#include <algorithm>

namespace cppcode { namespace taskflow {

TaskFlow::TaskFlow()
    : m_tasks()
{
}

TaskFlow::~TaskFlow()
{
    for (auto t : m_tasks)
    {
        if (t != nullptr)
        {
            delete t;
        }
    }
}

Task* TaskFlow::add(std::string taskName, TaskOperation op)
{
    m_tasks.push_back(new Task(std::move(taskName), op, *this));

    return m_tasks.back();
}

void TaskFlow::run()
{
    for (Task* t : m_tasks)
    {
        t->run();
    }

    std::unique_lock<std::mutex> lock(m_tasksMutex);
    m_allTasksFinished.wait(lock,
        [this]
        {
            return std::all_of(m_tasks.begin(), m_tasks.end(),
                               [](const Task* t)
                               {
                                   return t->finished();
                               });
        });
}

void TaskFlow::notify()
{
    std::lock_guard<std::mutex> lock(m_tasksMutex);
    m_allTasksFinished.notify_all();
}

}}
