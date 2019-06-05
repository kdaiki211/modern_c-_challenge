#include <iostream>
#include <string>
#include <regex>

constexpr uint32_t N = 7;

using namespace std;

int main(void) {
  string isbn, tmp;
  cin >> isbn;
  tmp = regex_replace(isbn, regex("[ISBN-]"), "");
  int len = tmp.length();
  assert(len == 10);
  uint32_t sum = 0;
  for (int i = 0; i < len - 1; i++) {
    sum += (tmp[i] - '0') * (10 - i);
  }
  const uint32_t r = sum % 11;
  const uint32_t cd = 11 - r;
  const char cd_c = (cd == 11) ? '0' : (cd == 10) ? 'X' : ('0' + cd);
  if (tmp[9] == cd_c) {
    cout << "Correct";
  } else {
    cout << "Wrong";
  }
  cout << endl;
  return 0;
}
