#include <iostream>
#include <filesystem> // C++17 から使用可

using namespace std;

size_t getSizeOfDirectory(string dir, bool followSymlink)
{
  size_t sz = 0;
  for (auto item : filesystem::directory_iterator(dir)) {
    if (item.is_directory()) {
      if (!followSymlink && item.is_symlink()) continue;
      sz += getSizeOfDirectory(item.path(), followSymlink);
    // } else if (followSymlink && item.is_symlink()) {
    //   sz += getSizeOfDirectory(filesystem::read_symlink(item.path()), followSymlink);
    } else {
      sz += item.file_size();
    }
  }
  return sz;
}

int main(void)
{
  cout << "followSymlink = false: " << getSizeOfDirectory(".", false) << endl;
  cout << "followSymlink = true : " << getSizeOfDirectory(".", true) << endl;
}

