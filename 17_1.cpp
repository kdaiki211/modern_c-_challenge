#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <cassert>

using namespace std;

template<typename T, int w, int h>
class array2d {
  public:
  array2d(initializer_list<T> init) {
    assert(w*h == init.size());
    const T* s = init.begin();
    for (auto i = 0; i < h; i++) {
      for (auto j = 0; j < w; j++) {
        value[i][j] = *s;
        s++;
      }
    }
  }

  void print(int n = 1) {
    for (auto i = 0; i < h; i++) {
      for (auto j = 0; j < w; j++) {
        cout << setw(n) << value[i][j] << " ";
      }
      cout << endl;
    }
  }

  private:
  T value[w][h];
};

// テストケースはほぼほぼ丸コピ👌
int main() {
  // 要素アクセス
  array2d<int, 2, 3> a {1, 2, 3, 4, 5, 6}; // 👈 初期化子リスト
  a.print();
  /*
  for (size_t i = 0; i < a.size(1); ++i)
    for (size_t j = 0; j < a.size(2); ++j)
      a(i, j) *= 2;

  // イテレーション
  std::copy(std::cbegin(a), std::cend(a),
    std::ostream_iterator<int>(std::cout, " "));

  // フィリング
  array2d<int, 2, 3> b;
  b.fill(1);

  // スワップ
  a.swap(b);

  // ムーブ
  array2d<int, 2, 3> c(std::move(b));
  */
}

