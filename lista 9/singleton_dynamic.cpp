#include <iostream>
#include "singleton_dynamic.h"

using namespace std;

void calls2()
{
    auto &p = Singleton::instance();
    p.calls();
}

Singleton &instance()
{
    return Singleton::instance();
}