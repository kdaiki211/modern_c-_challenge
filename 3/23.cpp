#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

template<typename T>
string bin2hex(vector<T> v)
{
  assert(sizeof(T) == 1);
  char tbl[] = { '0', '1', '2', '3',
                 '4', '5', '6', '7',
                 '8', '9', 'A', 'B',
                 'C', 'D', 'E', 'F' };
  string str;
  for (auto byte : v)
  {
    char c[3];
    c[0] = tbl[(byte & 0xF0) >> 4];
    c[1] = tbl[(byte & 0x0F) >> 0];
    c[2] = '\0';
    str += string(c);
  }

  return str;
}

int main(void)
{
  vector<uint8_t> bin0 = { 0xBA, 0xAD, 0xF0, 0x0D };
  vector<uint8_t> bin1 = { 1, 2, 3, 4, 5, 6 };
  cout << bin2hex<uint8_t>(bin0) << endl;
  cout << bin2hex<uint8_t>(bin1) << endl;
  return 0;
}
