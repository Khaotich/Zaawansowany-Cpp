#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

void get_product(const vector<double> x, const vector<double> y, promise<double> promise_)
{
  try
  {
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
      double sum = 0.0;
      for (int i = 0; i < x.size(); ++i)
      {
        sum += x[i] * y[i];
      }
      promise_.set_value(sum);
    }
  }
  catch(...)
  {
    promise_.set_exception(current_exception());
  }
}

int main()
{
  vector <double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector <double> y = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int threads_num = 10;
  double sum = 0.0;
  vector <pair<thread, future <double>>> threads;

  try
  {
    for(int i = 0; i < threads_num; ++i)
    {
      promise <double> pro;
      future <double> fut = pro.get_future();
      thread th(get_product, x, y, move(pro));
      threads.push_back(make_pair(move(th), move(fut)));
    }
  }
  catch(const exception& e)
  {
    cerr << e.what() << '\n';
  }
  
  for (auto &e : threads)
  {
    auto th = move(e.first);
    auto fut = move(e.second);
    sum = fut.get();
    th.join();
  }

  cout << "Wynik: " << sum << '\n';
}