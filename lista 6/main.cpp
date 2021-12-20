// #include <iostream>
// #include <vector>
// #include <thread>
// #include <future>

// using namespace std;

// double scalar_product(vector <double> x, vector <double> y, promise <double> a)
// {

// }

// int main()
// {

// }

#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>

using namespace std;

void get_product(vector<double> x, vector<double> y, promise<double> promise_)
{
  if((x.size() != y.size()) || x.empty() || y.empty())
  {
    throw logic_error("Niewłaściwe wektory");
  }
  else
  {
    double sum = inner_product(x.begin(), x.end(), y.begin(), 0.0);
    promise_.set_value(sum);
  }

}

int main()
{
  vector<double> x = {1, 2, 3, 4, 5, 6};
  vector<double> y = {1, 2, 3, 4, 5, 6};

  promise<double> promise_;
  future<double> future_ = promise_.get_future();

  try
  {
    thread work_thread(get_product, x, y, move(promise_));
    
    cout << "result=" << future_.get() << "\n";
    work_thread.join();
  }
  catch(const logic_error& e)
  {
    cerr << e.what() << '\n';
  }
}