#include <iostream>
#include <vector>
#include <string>

using namespace std;

string concat(vector<string> str, char delimiter)
{
  string ret_str;
  bool first_time = true;
  for (auto s : str)
  {
    ret_str += (!first_time ? string({delimiter, '\0'}) : "") + s;
    first_time = false;
  }
  return ret_str;
}

int main(void)
{
  vector<string> str0 = { "this", "is", "an", "example" };
  vector<string> str1;
  char delimiter = ' ';
  cout << "\"" << concat(str0, delimiter) << "\"" << endl;
  cout << "\"" << concat(str1, delimiter) << "\"" << endl;
}
