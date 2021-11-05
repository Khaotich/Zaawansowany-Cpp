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
    cout << "Konstruktor kopiujący \n";
    string text = org.content;
    char* tmp = new char[text.size() + 1];
    copy(text.begin(), text.end(), tmp);
    tmp[text.size()] = '\0';
    content = tmp;
}

A::A(A&& org) noexcept
{
    cout << "Konstruktor przenoszący \n";
    this->content = org.content;
    org.content = nullptr;
}

char* A::get()
{
    return content;
}

A::~A()
{
    delete[] content;
}
