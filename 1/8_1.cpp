#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int main(void) {
  for (uintmax_t d2 = 1; d2 < 10; d2++) {
    for (uintmax_t d1 = 0; d1 < 10; d1++) {
      for (uintmax_t d0 = 0; d0 < 10; d0++) {
        const uintmax_t value = 100 * d2 + 10 * d1 + 1 * d0;
        const uintmax_t s = pow(d2, 3) + pow(d1, 3) + pow(d0, 3);
        if (value == s) {
          cout << value << endl;
        }
      }
    }
  }
  return 0;
}
