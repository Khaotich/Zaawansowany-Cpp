#include <iostream>
#include "calls1.h"
#include "singleton_dynamic.h"

using namespace std;

int main()
{
    auto &p = Singleton::instance();
    p.calls();
    calls1();
    calls2();
    instance().calls();
}
