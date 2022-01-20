#include "engine.h"

using namespace std;

Engine::Engine(unsigned int interval, unsigned int fuel) : interval(interval), fuel(fuel)
{
    thread_ = thread(&Engine::startEngine, this);
}

Engine::~Engine()
{
    if(thread_.joinable()) thread_.join();
}

void Engine::startEngine()
{
    unique_lock<mutex> lock(mtx);
    while(!tanks.empty())
    {
        unsigned int currentFuel = tanks.front() -> download(fuel);
        if (currentFuel == 0) tanks.pop_front();
        lock.unlock();
        this_thread::sleep_for(chrono::seconds(interval));
        lock.lock();
    }
}

void Engine::connectTank(shared_ptr<Tank> &tank)
{
    cout << "Zbiornik paliwa podłączony \n";
    unique_lock<mutex> uniqueLock(mtx);
    tanks.push_back(tank);
}
