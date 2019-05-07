#include <iostream>
#include <cstdint>
#include <bitset>
#include <cassert>

using namespace std;

uint8_t decode_gray_code(const uint8_t nd, const uint8_t gray_code) {
  uint8_t decoded = 0;
  uint8_t prev_bit = 0;
  for (int16_t i = nd - 1; i >= 0; i--) {
    const uint8_t mask = 1 << i;
    prev_bit ^= (gray_code & mask) ? 1 : 0;
    decoded |= prev_bit << i;
  }
  return decoded;
}

int main(void) {
  constexpr int nd = 5;
  for (uint8_t i = 0; i <= 0x1f; i++) {
    const uint8_t gray_code = i ^ (i >> 1);
    const uint8_t decoded   = decode_gray_code(nd, gray_code);
    assert(i == decoded);
    cout << bitset<nd>(i) << " " << bitset<nd>(gray_code) << " " << bitset<nd>(decoded) << endl;
  }
  return 0;
}
