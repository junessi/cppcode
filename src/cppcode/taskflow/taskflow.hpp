#pragma once

#include <cppcode/taskflow/task.hpp>
#include <cppcode/taskflow/taskflow.hpp>
#include <vector>
#include <mutex>
#include <condition_variable>

namespace cppcode { namespace taskflow {

class TaskFlow
{
public:
    TaskFlow();
    ~TaskFlow();

    void run();
    void notify();
    Task* add(std::string taskName, TaskOperation op);

private:
    std::vector<Task*> m_tasks;
    std::condition_variable m_allTasksFinished;
    std::mutex m_tasksMutex;
};

}}
