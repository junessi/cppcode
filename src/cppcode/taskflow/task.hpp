#pragma once

#include <functional>
#include <mutex>
#include <vector>
#include <condition_variable>

namespace cppcode { namespace taskflow {

class TaskFlow;

using TaskOperation = std::function<void()>;

class Task
{
public:
    Task(std::string taskName, TaskOperation op, TaskFlow& parent);
    void run();
    bool finished() const;
    void precede(Task* t);
    void notify();

private:
    void addDependent(Task* t);
    void notifySuccessors();
    void waitForDependents();

    TaskOperation m_task;
    TaskFlow& m_parent;

    mutable std::mutex m_dependentsMutex;
    std::vector<Task*> m_dependents;
    std::condition_variable m_cvDependents;

    mutable std::mutex m_successorsMutex;
    std::vector<Task*> m_successors;

    mutable std::mutex m_finishFlagMutex;
    bool m_finished;
};

}}
