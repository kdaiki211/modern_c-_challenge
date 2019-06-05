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

  size_t size(int i) const {
    assert(i == 1 || i == 2);
    if (i == 1) {
      return h;
    } else {
      return w;
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

  // 👇 関数呼び出し演算子
  T& operator()(int i, int j) {
    return value[i][j];
  }

  // イテレータ用の色々
  // 参考文献: http://program.station.ez-net.jp/special/handbook/cpp/stl/iterator-make.asp
  // const_iterator cbegin() const {
  //   return &value[0][0];
  // }

  // const_iterator cend() const {
  //   return &value[w-1][h]

  private:
  T value[h][w];
};

// テストケースはほぼほぼ丸コピ👌
int main() {
  // 要素アクセス
  array2d<int, 2, 3> a {1, 2, 3, 4, 5, 6}; // 👈 初期化子リスト
  a.print();
  for (size_t i = 0; i < a.size(1); ++i)
    for (size_t j = 0; j < a.size(2); ++j)
      a(i, j) *= 2;
  a.print();

  // イテレーション
  // std::copy(std::cbegin(a), std::cend(a),
  //   std::ostream_iterator<int>(std::cout, " "));

  /*
  // フィリング
  array2d<int, 2, 3> b;
  b.fill(1);

  // スワップ
  a.swap(b);

  // ムーブ
  array2d<int, 2, 3> c(std::move(b));
  */
}

