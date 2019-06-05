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

int main(void) {
  uintmax_t N;
  cin >> N;
  cout << N << ": ";

  // consider special case
  if (N < 2) {
    cout << endl;
    return 1;
  }

  // calc prime numbers using sieve of eratosthenes
  vector<uintmax_t> prime_numbers = calc_prime_numbers(N);

  // trial division
  auto x = N;
  do {
    for (auto p : prime_numbers) {
      if (x % p == 0) {
        cout << p << " ";
        x /= p;
        break;
      }
    }
  } while (x > 1);
  cout << endl;

  return 0;
}
