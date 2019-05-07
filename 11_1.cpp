#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>

using namespace std;

int main(void) {
  uintmax_t N;
  cin >> N;

  // check special cases
  if (N == 0) {
    cout << "nulla" << endl;
    return 0;
  } else if (N >= 4000) {
    cout << "must be less than 4000" << endl;
    return 1;
  }

  vector<tuple<uint16_t, char>> tbl = {{1000, 'M'},
                                       {500,  'D'},
                                       {100,  'C'},
                                       {50,   'L'},
                                       {10,   'X'},
                                       {5,    'V'},
                                       {1,    'I'}};
  for (auto elm : tbl) {
    const uint16_t val = get<0>(elm);
    const char c       = get<1>(elm);
    const uint8_t n    = N / val;
    cout << setw(n) << setfill(c) << "";
    N %= val;
  }
  cout << endl;

  return 0;
}

