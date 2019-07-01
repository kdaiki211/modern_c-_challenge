#include <iostream>
#include <map>
#include <chrono>
#include <thread>

using namespace std;

template<typename duration>
int measureExecutionTime(void (*func)(void)) {
  const chrono::time_point t0 = chrono::high_resolution_clock::now();
  func();
  const chrono::time_point t1 = chrono::high_resolution_clock::now();
  return chrono::duration_cast<duration>(t1 - t0).count();
}

template<typename duration>
void measureAndPrintExecutionTime(void (*func)(void)) {
  string unit;
  if (typeid(duration) == typeid(chrono::seconds))
    unit = "s";
  else if (typeid(duration) == typeid(chrono::milliseconds))
    unit = "ms";
  else if (typeid(duration) == typeid(chrono::microseconds))
    unit = "us";
  else if (typeid(duration) == typeid(chrono::nanoseconds))
    unit = "ns";
  else
    unit = "unknown-unit";
    
  const int time = measureExecutionTime<duration>(func);
  cout << "time = " << time << " " << unit << endl;
}

/* target functions */
int add1(int x0, int x1) {
  this_thread::sleep_for(chrono::milliseconds(10));
  return x0 + x1;
}
int add2(int x0, int x1) {
  this_thread::sleep_for(chrono::milliseconds(20));
  return x0 + x1;
}
int add3(int x0, int x1) {
  this_thread::sleep_for(chrono::milliseconds(30));
  return x0 + x1;
}
/********************/

template<typename duration>
void test(void)
{
  measureAndPrintExecutionTime<duration>([](void) { add1(3, 5); });
  measureAndPrintExecutionTime<duration>([](void) { add2(5, 7); });
  measureAndPrintExecutionTime<duration>([](void) { add3(7, 9); });
}

int main(void) {
  test<chrono::seconds>();
  test<chrono::milliseconds>();
  test<chrono::microseconds>();
  test<chrono::nanoseconds>();
}

/*
time = 0 s
time = 0 s
time = 0 s
time = 12 ms
time = 22 ms
time = 35 ms
time = 12140 us
time = 20328 us
time = 32145 us
time = 12573415 ns
time = 24841270 ns
time = 30079782 ns
*/
