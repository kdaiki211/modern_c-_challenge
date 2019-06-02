#include <iostream>
#include <string>

using namespace std;

string get_max_palindrome(string str)
{
  auto len_max = 0;
  string palindrome;

  for (int s0 = 0; s0 < str.length(); s0++)
  {
    for (int e0 = str.length() - 1; e0 >= s0; e0--)
    {
      if (str[s0] == ' ') continue;
      auto s = s0;
      auto e = e0;
      while (s <= e && str[s] == str[e])
      {
        s++; e--;
      }
      if (s > e)
      {
        string candidate = str.substr(s0, e0 - s0 + 1);
        if (palindrome.length() < candidate.length())
        {
          palindrome = candidate;
        }
      }
    }
  }

  return palindrome;
}

int main(void)
{
  // http://www.guinnessworldrecords.com/world-records/longest-palindromic-word
  cout << "\"" << get_max_palindrome("i went to saippuakivikauppias yesterday") << "\"" << endl;
}
