#ifndef List_H
#define List_H

#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include <queue>
#include <condition_variable>
#include <atomic>

using namespace std;
using Task = function<double()>;

class List
{
public:
    List(int numThreads);
    ~List();
    void add_task(const Task& task);
    double average() const;

private:
    void start(int numThreads);
    void run();
    void stop() noexcept;

    vector<thread> threads;
    queue<Task> tasks;
    mutex mutex_;
    condition_variable cv;

    double sum;
    bool stop_;
    atomic<int> count;
};
#endif // List_H