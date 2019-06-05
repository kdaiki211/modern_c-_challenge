#include <iostream>
#include <cstdint>
#include <type_traits>
#include <tuple>

using namespace std;

template<typename T> T gcd(T m, T n) {
  static_assert(is_integral<T>::value == true, "specified typename is not a integral type");
  if (m < n) swap(m, n);
  while (n) tie(m, n) = [&] () -> tuple<T, T> { return { n, m % n }; } ();
  return m;
}

int main(void) {
  uintmax_t m, n;
  cin >> m >> n;
  cout << gcd(m, n) << endl;
  return 0;
}
