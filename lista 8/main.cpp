#include <iostream>
#include <memory>
#include "engine.h"
#include "tank.h"

using namespace std;

int main()
{
    Engine engine1(2, 5);
    Engine engine2(1, 1);
    Engine engine3(3, 2);

    list <shared_ptr<Tank>> tanks;

    for(int i = 0; i < 10 ; i++) tanks.push_back(make_shared<Tank>(1));

    for(auto &tank : tanks)
    {
        engine1.connectTank(tank);
        engine2.connectTank(tank);
        engine3.connectTank(tank);
    }
}
