#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string capitalize(string str)
{
  string ret_str;
  bool capital = true;
  for (auto c : str)
  {
    if (capital)
      ret_str += toupper(c);
    else
      ret_str += tolower(c);
    capital = c == ' ';
  }

  return ret_str;
}

int main(void)
{
  cout << capitalize("tHe c++ cHaLleNGEr") << endl;
  return 0;
}

