#include <iostream>
#include "a.h"

using namespace std;

int main()
{
    string a = "Witam";
    A siema(a);
    A siema2(siema);
    A siema3(move(siema2));
    //cout << "Siema2 " << siema2.get() << endl;
    cout << "Siema3 " << siema3.get() << endl;
}
