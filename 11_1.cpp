#include <iostream>
#include <cstdint>
#include <map>

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

  // FIXME: ソートしたくない…
  map<uint16_t, char> tbl = {{1000, 'M'},
                             {500,  'D'},
                             {100,  'C'},
                             {50,   'L'},
                             {10,   'X'},
                             {5,    'V'},
                             {1,    'I'}};
  for (auto elm : tbl) {
    cout << elm.first << " " << elm.second << endl;
  }
  return 0;
}

