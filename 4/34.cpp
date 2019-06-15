#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int main(void)
{
  const string filePath = "hoge.txt";
  const string tmpFilePath = filePath + ".tmp";
  ifstream ifs;
  ofstream ofs;

  ifs.open(filePath);
  if (!ifs.is_open()) return 1;
  ofs.open(tmpFilePath);
  if (!ofs.is_open()) return 2;

  for (string line; getline(ifs, line); )
    if (line != "") ofs << line << endl;

  ofs.close();
  ifs.close();

  remove(filePath.c_str());
  rename(tmpFilePath.c_str(), filePath.c_str());
}
