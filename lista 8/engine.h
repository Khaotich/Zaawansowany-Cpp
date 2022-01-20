#ifndef ENGINE_H
#define ENGINE_H

#include "tank.h"
#include <list>
#include <mutex>
#include <memory>
#include <thread>
#include <iostream>

using namespace std;

class Engine
{
private:
    list <shared_ptr<Tank>> tanks;
    unsigned int interval;
    unsigned int fuel;
    mutex mtx;
    thread thread_;

    void startEngine();

public:
    Engine(unsigned int interval, unsigned fuel);
    ~Engine();
    void connectTank(shared_ptr<Tank> &tank);
};
#endif //ENGINE_H
