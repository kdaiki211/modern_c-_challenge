#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(void)
{
  vector<int> row = { 1 };
  constexpr int N = 10;
  constexpr int w = 4;
  for (size_t i = 0; i < N; i++) {
    // print
    cout << string(w/2 * (N - i), ' ');
    for (auto v : row) {
      cout << setw(w) << v;
    }
    cout << endl;

    // update row
    vector<int> new_row = { 1 };
    for (int j = 0; j < i; j++) {
      new_row.push_back(row[j] + row[j + 1]);
    }
    new_row.push_back(1);
    row = new_row;
  }
  return 0;
}

