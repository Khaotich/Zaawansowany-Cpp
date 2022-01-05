#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <numeric>

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
  vector <double> z = {1, 2, 3, 4};
  vector <double> results;
  
  int threads_num = 10;
  vector <thread> threads;
  vector <future<double>> futures;


  try
  {
    for(int i = 0; i < threads_num; ++i)
    {
      promise <double> pro;
      future <double> fut = pro.get_future();
      
      if(i<9) 
      {
        thread th(get_product, x, y, move(pro));
        threads.push_back(move(th));
        futures.push_back(move(fut));
      }
      else
      {
        thread th(get_product, x, z, move(pro));
        threads.push_back(move(th));
        futures.push_back(move(fut));
      }
    }
  }
  catch(const exception& e)
  {
    cerr << e.what() << '\n';
  }

  try
  {
    for (auto &&f : futures)
    {
      results.push_back(f.get());
    }
  }
  catch(const std::exception& e)
  {
    cerr << e.what() << '\n';
  }
  
  int i = 0;
  for (auto &&r : results)
  {
    ++i;
    cout << "Wynik iloczynu skalarnego " << i << ": " << r << endl;
  }

  for (auto &&th : threads)
  {
    th.join();
  }
  
  cout << "\nSuma iloczynów skalarnych: " << accumulate(results.begin(), results.end(), 0) << '\n';
}