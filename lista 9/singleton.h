#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

class Singleton
{
private:
    Singleton();
    static shared_ptr<Singleton> singleton;
    static mutex mutex_;
    int count;

public:
    static Singleton &instance();
    void calls();
    ~Singleton();
};

#endif //SINGLETON_H