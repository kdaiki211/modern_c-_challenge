#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string delimiters)
{
  vector<string> ret_str;
  string::iterator crop_start = str.begin();
  for (string::iterator it = str.begin(); it != str.end(); it++)
  {
    if (delimiters.find(*it) != string::npos)
    {
      string::iterator crop_end = it;
      if (crop_start != crop_end)
        ret_str.push_back(string(crop_start, crop_end));
      crop_start = crop_end + 1;
    }
  }
  ret_str.push_back(string(crop_start, str.end()));
  return ret_str;
}

int main(void)
{
  string delimiters = ",.! ";
  auto str = split("this is,an!example.hoge...fuga!,.piyo", delimiters);
  for (auto s : str)
  {
    cout << "\"" << s << "\"" << endl;
  }
}

