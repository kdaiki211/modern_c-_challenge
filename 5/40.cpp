#include <iostream>
#include <chrono>
#include "date/date.h"

using namespace std;
using namespace date;
int main(void)
{
  constexpr auto date1 = July/2/2019;
  constexpr auto date2 = July/24/2020;
  cout << abs(sys_days{date2} - sys_days{date1}) << endl;
  cout << abs(sys_days{date1} - sys_days{date2}) << endl;
}

/*
388d
388d
*/
