#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

using namespace std;

int main(void) {
  uintmax_t N;
  cin >> N;
  const uintmax_t sqrtN = (uintmax_t)ceil(sqrt(N));

  // consider special case
  if (N < 2) {
    cout << "no prime number found" << endl;
    return 1;
  }

  // sieve of eratosthenes
  vector<uintmax_t> candidate(N-1);
  for (uintmax_t i = 0; i < N-1; i++) {
    candidate[i] = i+2;
  }
  for (uintmax_t i = 0; i < candidate.size(); i++) {
    uintmax_t p = candidate[i];
    if (p > sqrtN) break;
    for (uintmax_t m = p*2; m <= N; m += p) {
      candidate.erase(remove(candidate.begin(), candidate.end(), m), candidate.end());
    }
  }

  // show sexy primes
  for (auto s = candidate.begin(); s != candidate.end(); s++) {
    for (auto e = s + 1; e != candidate.end(); e++) {
      if (*e - *s == 6) {
        cout << "(" << *s << ", " << *e << ")" << endl;
      }
    }
  }

  return 0;
}
