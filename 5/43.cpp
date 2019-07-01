#include <iostream>
#include <chrono>
#include "../external/date/include/date/date.h"
#include "../external/date/include/date/iso_week.h"
#include "../external/date/include/date/tz.h"

using namespace std;
using namespace date;
using namespace iso_week;
using namespace std::chrono_literals;

int main(void)
{
  auto jp_tm = make_zoned("Asia/Tokyo", local_days{December/30/1978} + 12h + 1min);
  auto tz_list = {"America/New_York", "Asia/Tehran"};
  std::cout << "time in Japan : " << jp_tm << endl;
  for (auto tz : tz_list) {
    auto local_tm = make_zoned(tz, jp_tm);
    std::cout << "local time (" << tz << ") : " << local_tm << endl;
  }
}

/*
time in Japan : 1978-12-30 12:01:00 JST
local time (America/New_York) : 1978-12-29 22:01:00 EST
local time (Asia/Tehran) : 1978-12-30 07:01:00 +04
*/
