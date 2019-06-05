#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

template<typename T>
vector<T> hex2byte(string str)
{
  map<char, uint8_t> tbl;
  tbl['0'] = 0x0;
  tbl['1'] = 0x1;
  tbl['2'] = 0x2;
  tbl['3'] = 0x3;
  tbl['4'] = 0x4;
  tbl['5'] = 0x5;
  tbl['6'] = 0x6;
  tbl['7'] = 0x7;
  tbl['8'] = 0x8;
  tbl['9'] = 0x9;
  tbl['a'] = 0xa;
  tbl['b'] = 0xb;
  tbl['c'] = 0xc;
  tbl['d'] = 0xd;
  tbl['e'] = 0xe;
  tbl['f'] = 0xf;
  tbl['A'] = 0xa;
  tbl['B'] = 0xb;
  tbl['C'] = 0xc;
  tbl['D'] = 0xd;
  tbl['E'] = 0xe;
  tbl['F'] = 0xf;

  vector<T> v;
  bool flush = false;
  char buf;
  for (auto c : str)
  {
    const uint8_t b = tbl[c];
    if (flush)
    {
      v.push_back((buf << 4) | b);
    } else {
      buf = b;
    }
    flush = !flush;
  }
  if (flush) v.push_back(buf);
  return v;
}

void print_hex(string str)
{
  auto bytes = hex2byte<uint8_t>(str);
  for (auto byte : bytes)
  {
    cout << hex << setfill('0') << setw(2) << (unsigned int)byte;
  }
  cout << endl;
}

int main(void)
{
  string str0 = "BAADF00D";
  string str1 = "baadf00d";
  string str2 = "010203040506";
  print_hex(str0);
  print_hex(str1);
  print_hex(str2);
}
