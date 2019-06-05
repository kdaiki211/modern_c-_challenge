#include <iostream>
#include <regex>
#include <string>

using namespace std;

regex re0("(\\d{2})\\.(\\d{2})\\.(\\d{4})");
regex re1("(\\d{2})\\-(\\d{2})\\-(\\d{4})");
string pat = "$3-$2-$1";

string cvt_date_style(string str)
{
  str = regex_replace(str, re0, pat);
  str = regex_replace(str, re1, pat);
  return str;
}

int main(void)
{
  cout << cvt_date_style("reiwa 01.05.2019 01-05-2019 01.05-2019 01-05.2019") << endl;
}

