#include <iostream>
#include <regex>

using namespace std;

regex re("(\\w+)://(\\w+:\\w+@)?([a-zA-Z0-9_\\-.]+)(:\\d+)?([a-zA-Z_\\-./]+)?(\\?[^#]*)?(#.*)?");

void print_url_parts(string str)
{
  smatch sm;
  if (regex_search(str, sm, re))
  {
    cout << "MATCHED!" << endl;
    for (int i = 1; i < sm.length(); i++)
    {
      if (sm[i] != "")
        cout << sm[i] << endl;
    }
  } else {
    cout << "not matched..." << endl;
  }
}

int main(void)
{
  // https://webtan.impress.co.jp/e/2010/03/09/7539
  print_url_parts("http://yasuda:pass@www.example.com:8080/news/index.htm?page=2&msg=yes#hot");
}

