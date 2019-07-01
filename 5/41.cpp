#include <iostream>
#include <chrono>
#include "../external/date/include/date/date.h"

using namespace std;
using namespace date;

int get_dow(sys_days sd)
{
  return weekday{sd}.iso_encoding();
}

int main(void)
{
  cout << get_dow(June/30/2019) << endl; // Sun
  cout << get_dow(July/1/2019) << endl;  // Mon
  cout << get_dow(July/2/2019) << endl;  // Tue
  cout << get_dow(July/3/2019) << endl;  // Wed
  cout << get_dow(July/4/2019) << endl;  // Thu
  cout << get_dow(July/5/2019) << endl;  // Fri
  cout << get_dow(July/6/2019) << endl;  // Sat
}

/*
7
1
2
3
4
5
6
*/
