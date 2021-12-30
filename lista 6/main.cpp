#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <mutex>

using namespace std;

void get_product(const vector <double> x, const vector <double> y, promise <double> promise_)
{
  static mutex m;
  lock_guard <mutex> lk(m);
  static int i = -1;
  
  if(x.empty() || y.empty())
  {
    throw logic_error("Jeden z wektorów jest pusty !!!");
  }
  else if(x.size() != y.size())
  {
    throw logic_error("Nieprawidłowy rozmiar wektorów !!!");
  }
  else
  {
    ++i;
    promise_.set_value(x[i] * y[i]);
  }
}

int main()
{
  vector <double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector <double> y = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int threads_num = 10;
  double sum = 0.0;
  vector <pair < thread, future <double>>> threads;

  try
  {
    for(int i = 0; i < threads_num; ++i)
    {
        promise <double> pro;
        future <double> fut = pro.get_future();
        thread th(get_product, x, y, move(pro));
        threads.push_back(make_pair(move(th), move(fut)));
    }
    for(auto& e : threads)
    {
        auto th = move(e.first);
        auto fut = move(e.second);
        sum += fut.get();
        th.join();
    }
    
    cout << "Wynik: " << sum << '\n';
  }
  catch(const logic_error& e)
  {
    cerr << e.what() << '\n';
  }
}