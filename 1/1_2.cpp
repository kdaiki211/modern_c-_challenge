#include <iostream>
#include <cstdint>
#include <type_traits>

using namespace std;

template<typename T> T sum_up_multiple(const T step, T max) {
  static_assert(is_integral<T>::value == true, "specified typename is not a integral type");
  T n = max / step;
  max = n * step;
  return (step + max) * n / 2;
}

int main(void) {
  uintmax_t max;
  cin >> max;
  auto sum = sum_up_multiple(static_cast<uintmax_t>(3), max);
  sum += sum_up_multiple(static_cast<uintmax_t>(5), max);
  sum -= sum_up_multiple(static_cast<uintmax_t>(3*5), max);
  cout << sum << endl;
  return 0;
}
