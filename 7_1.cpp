#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;

vector<uintmax_t> calc_prime_numbers(uintmax_t N) {
  const uintmax_t sqrtN = (uintmax_t)ceil(sqrt(N));
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
  return candidate;
}

vector<uintmax_t> calc_divisors(vector<uintmax_t>& prime_numbers, uintmax_t value) {
  vector<uintmax_t> d{1};

  for (auto s = prime_numbers.begin(); s != prime_numbers.end(); s++) {
    if (*s >= value) break; // skip larger values and non-proper divisor (prime value)
    // check multiples of *s
    for (auto n = *s; n < value; n += *s) {
      if (value % n == 0) {
        d.push_back(n);
      }
    }
  }
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());

  return d;
}

int main(void) {
  uintmax_t N;
  cin >> N;

  // consider special case
  if (N < 2) {
    cout << "no prime number found" << endl;
    return 1;
  }

  // calc prime numbers using sieve of eratosthenes
  vector<uintmax_t> prime_numbers = calc_prime_numbers(N); /* FIXME: lack of prime number elements... */

  // search amicable numbers
  for (uintmax_t i = 1; i <= N; i++) {
    vector<uintmax_t> d1 = calc_divisors(prime_numbers, i);
    const uintmax_t sumOfD1 = accumulate(d1.begin(), d1.end(), 0); // use proper divisors only
    vector<uintmax_t> d2 = calc_divisors(prime_numbers, sumOfD1);
    const auto sumOfD2 = accumulate(d2.begin(), d2.end(), 0); // use proper divisors only
    if (i < sumOfD1 && i == sumOfD2) {
      cout << "(" << i << ", " << sumOfD1 << ")" << endl;
    }
  }

  return 0;
}
