#ifndef A_H
#define A_H

#include <iostream>

using namespace std;

class A
{

private:
    char* content;

public:
    A(const string& text);
    A(const A& org);
    A(A&& org) noexcept;
    char* get();
    ~A();
};

#endif // A_H
