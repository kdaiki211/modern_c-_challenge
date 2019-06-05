#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <ios>

using namespace std;

enum class Stat { RUNNING, SUSPENDED };
map<Stat, string> StatString= { { Stat::RUNNING,   "Running" },
                                { Stat::SUSPENDED, "Suspended" } };
enum class Platform { _32_BIT, _64_BIT };
map<Platform, string> PlatformString = { { Platform::_32_BIT, "32-bit" },
                                         { Platform::_64_BIT, "64-bit" } };

using NameType       = string;
using IdentifierType = int;
using StatusType     = Stat;
using AccountType    = string;
using MemoryType     = size_t;
using PlatformType   = Platform;

using Proc = tuple<NameType,
                   IdentifierType,
                   StatusType,
                   AccountType,
                   MemoryType,
                   PlatformType>;
using ProcList = vector<Proc>;

void prepareList(ProcList& procList)
{
  procList = { make_tuple("skype.exe",
                          22456,
                          Stat::SUSPENDED,
                          "marius.bancila",
                          656 * 1024,
                          Platform::_64_BIT),
               make_tuple("explorer.exe",
                          7108,
                          Stat::RUNNING,
                          "marius.bancila",
                          29529 * 1024,
                          Platform::_64_BIT),
               make_tuple("chrome.exe",
                          10100,
                          Stat::RUNNING,
                          "marius.bancila",
                          227756 * 1024,
                          Platform::_32_BIT),
               make_tuple("cmd.exe",
                          512,
                          Stat::RUNNING,
                          "SYSTEM",
                          48 * 1024,
                          Platform::_64_BIT),
               make_tuple("chrome.exe",
                          1044,
                          Stat::RUNNING,
                          "marius.bancila",
                          25180 * 1024,
                          Platform::_32_BIT)
             };
}

void showList(ProcList procList)
{
  // sort by process name
  sort(procList.begin(), procList.end());
  for (auto proc : procList)
    cout << left
         << setw(14) << get<0>(proc) << " "
         << setw(6)  << get<1>(proc) << " "
         << setw(10) << StatString[get<2>(proc)] << " "
         << setw(15) << get<3>(proc) << " " << " "
         << right
         << setw(6)  << get<4>(proc) / 1024 << " "
         << left
         << setw(6)  << PlatformString[get<5>(proc)] << endl;
}

int main(void)
{
  ProcList procList;
  prepareList(procList);
  showList(procList);
  return 0;
}

