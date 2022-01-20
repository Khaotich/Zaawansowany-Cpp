#include <iostream>
#include "calls1.h"

using namespace std;

void calls1()
{
    auto &p = Singleton::instance();
    p.calls();
}