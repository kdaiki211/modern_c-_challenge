#include <iostream>
#include <cmath>

using namespace std;

tuple<double, double, double, double>
get_next_values(const double a, const double b, const double t, const double p) {
  return { (a + b) / 2.,
           sqrt(a * b),
           t - p * pow(a - (a + b) / 2., 2),
           2 * p };
}

int main(void) {
  // ガウス＝ルジャンドルのアルゴリズム
  double a = 1.;
  double b = 1. / sqrt(2);
  double t = 1. / 4.;
  double p = 1.;
  const uint32_t n = 1;
  for (uint32_t i = 0; i < n; i++) {
    auto next_values = get_next_values(a, b, t, p);
    a = get<0>(next_values);
    b = get<1>(next_values);
    t = get<2>(next_values);
    p = get<3>(next_values);
  }
  cout << pow(a + b, 2) / (4 * t) << endl;
  return 0;
}
