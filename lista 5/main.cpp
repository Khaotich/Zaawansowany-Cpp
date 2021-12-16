#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

//zadanie 1
int getId()
{
  static mutex m_;
  static int count = 0;
  thread_local int id = ++count;
  lock_guard <mutex> lock(m_);
  return id;
}

//zadanie 2
void getText(const string& text)
{
  static mutex m;
  lock_guard <mutex> lock(m);
  cout << "Thread o id " << getId() << ": " + text << "\n";
}

//zadanie 3
void getAsync(launch mode)
{
  static int run_count = 0;
  if(run_count < 3)
  {
    ++run_count;
    future <void> f = async(mode, getAsync, mode);
    getText("async x" + to_string(run_count));
    f.get();
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
