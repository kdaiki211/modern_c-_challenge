#include <iostream>
#include <set>

using namespace std;

int main(void) {
  // get max from stdin
  int max;
  cin >> max;

  // calc multiple of 3 and 5
  set<int> A;
  for (auto i = 3; i <= max; i += 3) {
    A.insert(i);
  }
  for (auto i = 5; i <= max; i += 5) {
    A.insert(i);
  }

  // sum up A's elements
  int sum = 0;
  for (auto a : A) {
    sum += a;
  }

  cout << sum << endl;
  return 0;
}
