#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <numeric>

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

  // calc prime numbers using sieve of eratosthenes
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

  // judge whether i is an abundant number
  // https://en.wikipedia.org/wiki/Abundant_number
  for (uintmax_t i = 1; i <= N; i++) {
    vector<uintmax_t> d{1};

    // calc divisors
    for (auto s = candidate.begin(); s != candidate.end(); s++) {
      if (*s >= i) break; // skip larger values and prime values
      // check multiples of *s
      for (auto n = *s; n < i; n += *s) {
        if (i % n == 0) {
          d.push_back(n);
        }
      }
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    /* 
    cout << "[?] " << i << ": ";
    for (auto value : d) {
      cout << value << " ";
    }
    cout << endl;
    */

    // [note]
    // sum > 2 * val
    // sum - val > val

    // judge
    const auto sum = accumulate(d.begin(), d.end(), 0);
    if (sum > i) {
      cout << i << ": " << (sum - i) << endl;
    }
  }

  return 0;
}
