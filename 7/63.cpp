#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
const int N = 99999999;

template<typename T>
T min_63(vector<T> num)
{
  const int num_thread = 8;
  const int num_elem_per_th = num.size() / num_thread;
  future<T> f[num_thread];
  for (int i = 0; i < num_thread; i++) {
    typename vector<T>::iterator first = num.begin() + i * num_elem_per_th;
    typename vector<T>::iterator last  = (i == num_thread - 1) ?
                                         num.end() :
                                         num.begin() + i * num_elem_per_th;
    f[i] = async(launch::async,
             [&]() {
               return *min_element(first, last);
             });
  }
  vector<T> buf;
  for (int i = 0; i < num_thread; i++) {
    buf.push_back(f[i].get());
  }
  return *min_element(buf.begin(), buf.end());
}

int main(void)
{
  vector<int> num;
  for (int i = 0; i < N; i++) num.push_back(N - i);
  cout << min_63<int>(num) << endl;
  return 0;
}

