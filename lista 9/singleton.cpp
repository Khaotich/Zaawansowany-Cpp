#include "singleton.h"

using namespace std;

shared_ptr<Singleton> Singleton::singleton;
mutex Singleton::mutex_;

Singleton::Singleton() : count(0)
{
    cout << this << "+\n";
}

Singleton &Singleton::instance()
{
    lock_guard<mutex> lock(mutex_);
    
    if (Singleton::singleton == nullptr) Singleton::singleton = make_shared<Singleton>(Singleton());
    return *Singleton::singleton;
}

void Singleton::calls()
{
    ++count;
    cout << "Number of calls:" << count << "\n";
    cout << "Object address:" << Singleton::singleton.get() << "\n";
}

Singleton::~Singleton()
{
    cout << Singleton::singleton.get() << "-\n";
}