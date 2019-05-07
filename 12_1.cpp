#include <iostream>
#include <cstdint>
#include <tuple>

using namespace std;

uint32_t collatz(uint32_t n) {
  uint32_t len = 1;
  while (n != 1) {
    if (n & 1) {
      n = 3 * n + 1;
    } else {
      n = n / 2;
    }
    len++;
  }
  return len;
}

int main(void) {
  tuple<uint32_t, uint32_t> ans = {};
  for (uint32_t i = 1; i <= 1000000; i++) {
    const uint32_t len = collatz(i);
    if (get<1>(ans) < len) {
      ans = {i, len};
    }
  }
  cout << get<0>(ans) << " " << get<1>(ans) << endl;
  return 0;
}
