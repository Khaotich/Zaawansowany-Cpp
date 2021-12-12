#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

//zadanie 1
int getId()
{
  static int id = 0;
  return ++id;
}

//zadanie 2
mutex m;
void getText(string text)
{
  lock_guard <mutex> lock(m);
  cout << "Thread " << getId() << ": " + text << "\n";
}

//zadanie 3
int run_count = 0;
void getAsync(launch mode)
{
  if(run_count < 3)
  {
    ++run_count;
    future <void> f = async(mode, getAsync, mode);
    getText("async x" + to_string(run_count));
  }
}

int main()
{
  thread thr1(getText, "Test 1");
  thread thr2(getText, "Test 2");
  thr1.join();
  thr2.join();

  getAsync(launch::async);
  //getAsync(launch::deferred);
}
