#include <iostream>
#include <list>
#include <regex>
#include <cassert>

using namespace std;

regex re("[A-Z]{3}-[A-Z]{2} \\d{3,4}");

bool is_valid_number_plate(string str)
{
  return regex_match(str, re);
}

vector<string> get_valid_number_plates(string str)
{
  vector<string> valid_number_plates;
  smatch sm;
  while (regex_search(str, sm, re))
  {
    valid_number_plates.push_back(sm[0]);
    if (sm.position() + 1 == str.length()) break;
    str = str.substr(sm.position()+1, str.length() - 1);
  }
  return valid_number_plates;
}

void test_is_valid_number_plate(string str)
{
  if (is_valid_number_plate(str))
  {
    cout << "VALID";
  } else {
    cout << "INVALID";
  }
  cout << ": \"" << str << "\"" << endl;
}

void test_get_valid_number_plates(string str)
{
  auto valid_number_plates = get_valid_number_plates(str);
  if (valid_number_plates.size() > 0)
    cout << "\"" << str << "\":" << endl;
  else
    cout << "no valid number plates found in \"" << str << "\"" << endl;
  for (auto s : valid_number_plates)
  {
    cout << "  -> " << s << endl;
  }
}

int main(void)
{
  test_is_valid_number_plate("ABC-DE 123");
  test_is_valid_number_plate(" ABC-DE 123");
  test_is_valid_number_plate("ABC-DE 123 ");
  test_is_valid_number_plate("ABC-DE123");
  test_is_valid_number_plate("!BC-DE 123");
  test_is_valid_number_plate("hoge: ABC-DE 123, fuga: FGH-IJ 456");
  test_get_valid_number_plates("hoge: ABC-DE 123, fuga: FGH-IJ 456");
}

