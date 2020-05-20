#include <cppcode/taskflow/task.hpp>
#include <cppcode/taskflow/taskflow.hpp>
#include <thread>

namespace cppcode { namespace taskflow {

Task::Task(std::string taskName, TaskOperation op, TaskFlow& parent)
    : m_task(std::move(op))
    , m_parent(parent)
    , m_finished(false)
{}

void Task::run()
{
    waitForDependents();

    std::thread t(m_task);
    t.join();

    m_finished = true;

    notifySuccessors()

    m_parent.notify();
}

void Task::notifySuccessors()
{
    std::unique_lock<std::mutex> depLock(m_dependentsMutex);
    m_cvDependents.wait(depLock, [this]()
                                 {
                                     for (const auto t : m_dependents)
                                     {
                                         if ((t != nullptr) && (!t->finished()))
                                         {
                                             return false;
                                         }
                                     }
                                     return true;
                                 });
}

void Task::waitForDependents()
{
    for (Task* t : m_successors)
    {
        if (t != nullptr)
        {
            t->notify();
        }
    }
}

void Task::notify()
{
    std::lock_guard<std::mutex> lock(m_dependentsMutex);
    m_cvDependents.notify_all();
}

bool Task::finished() const
{
    std::lock_guard<std::mutex> lock(m_finishFlagMutex);
    return m_finished;
}

void Task::precede(Task* t)
{
    if (t != nullptr)
    {
        t->addDependent(this);
        m_successors.push_back(t);
    }
}

void Task::addDependent(Task* t)
{
    m_dependents.push_back(t);
}

}}
