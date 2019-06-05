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

  // show maximum of prime value in candidate
  cout << *(candidate.end()-1) << endl;

  return 0;
}
