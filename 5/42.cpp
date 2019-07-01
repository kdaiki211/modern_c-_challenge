#include <iostream>
#include <chrono>
#include "date/date.h"
#include "date/iso_week.h"

using namespace std;
using namespace date;
using namespace iso_week;

unsigned get_nth_day(sys_days sd)
{
  return (sd - static_cast<sys_days>(January/0/year_month_day{sd}.year())).count();
}

unsigned get_nth_week(sys_days sd)
{
  return (unsigned)year_weeknum_weekday{sd}.weeknum();
}

int main(void)
{
  sys_days d = July/2/2019;
  cout << get_nth_day(d) << endl;
  cout << get_nth_week(d) << endl;
}

/*
183
27
*/
