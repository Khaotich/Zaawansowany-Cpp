#include <iostream>
#include "list.h"

using namespace std;
using Task = function<double()>;

int main()
{
    List list = List(10);
    Task task = []{return 8.9 / 3;};

    for(int i = 0; i < 8; ++i) list.add_task(task);

    cout << "Average = " << list.average() << "\n";
}
