#include <iostream>
#include "a.h"

using namespace std;

A::A(const string& text)
{
    char* tmp = new char[text.size() + 1];
    copy(text.begin(), text.end(), tmp);
    tmp[text.size()] = '\0';
    content = tmp;
}

A::A(const A& org)
{
    string text = org.content;
    char* tmp = new char[text.size() + 1];
    copy(text.begin(), text.end(), tmp);
    tmp[text.size()] = '\0';
    content = tmp;
}

//////////////
A& A::operator=(A&& org){
   content = move(org.content);
   return *this;
}

A::A(A&& org) : content(move(org.content))
{
    org.content = nullptr;
}
//////////////

char* A::get()
{
    return content;
}

A::~A()
{
    delete[] content;
}
