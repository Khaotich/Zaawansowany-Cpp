#include <iostream>
#include "List.h"

using namespace std;
using Task = function<double()>;

List::List(int numThreads) : stop_(false), count(0), sum(0)
{
    start(numThreads);
}

List::~List()
{
    stop();
}

void List::add_task(const Task& task)
{
    {
        unique_lock<mutex> lock(mutex_);
        tasks.push(move(task));
    }  
    cv.notify_one();
}

void List::run()
{
    unique_lock<mutex> lock(mutex_);
    while(!stop_)
    {
        cv.wait(lock, [this] { return (!tasks.empty() || stop_);});

        if(!tasks.empty())
        {
            auto op = move(tasks.front());
            tasks.pop();
            lock.unlock();

            ++count;
            sum += op();

            lock.lock();
        }
    }
}

double List::average() const
{
    return sum / count;
}

void List::start(int numThreads)
{
    lock_guard<mutex> guard(mutex_);
    for(int i = 0; i < numThreads; i++) threads.emplace_back(&List::run, this);
}

void List::stop() noexcept
{
   {
        unique_lock<mutex> lock{mutex_};
        stop_ = true;
   }
    cv.notify_all();
    for (auto & mThread : threads) if(mThread.joinable()) mThread.join();
}