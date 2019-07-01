#include <iostream>
#include <iomanip>
#include <chrono>
#include "../external/date/include/date/date.h"
#include "../external/date/include/date/iso_week.h"

using namespace std;
using namespace date;

void show_calendar(int y, unsigned m)
{
  year_month_day ymd{year{y}, month{m}, day{1}};
  weekday wd{ymd};
  year_month_day_last ymdl{year{y}, month_day_last{month{m}}};
  unsigned dow = wd.iso_encoding() - 1;
  unsigned last_day = static_cast<unsigned>(ymdl.day());
  unsigned cnt = dow;

  cout << y << "/" << m << endl;
  cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;
  cout << string(4*dow, ' ');
  for (unsigned d = 1; d <= last_day; d++) {
    cout << setw(3) << d << " ";
    cnt++;
    if (cnt >= 7) {
      cout << endl;
      cnt = 0;
    }
  }
  cout << endl;
}

int main(void)
{
  show_calendar(2018, 7);
  show_calendar(2019, 2);
  show_calendar(2019, 6);
  show_calendar(2019, 7);
}
