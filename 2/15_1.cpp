#include <iostream>
#include <cassert>
#include <string>

using namespace std;

class Ipv4 {
  public:
    static const int numOfFields = 4;
    Ipv4() {
      memset(this->field, 0, sizeof(this->field));
    }
    Ipv4(const uint8_t field_0, const uint8_t field_1, const uint8_t field_2, const uint8_t field_3) {
      field[0] = field_0;
      field[1] = field_1;
      field[2] = field_2;
      field[3] = field_3;
    }
    uint8_t getField(uint8_t idx) {
      assert(idx < 4);
      return field[idx];
    }
    void setField(uint8_t idx, uint8_t value) {
      field[idx] = value;
    }
    
  private:
    uint8_t field[numOfFields];
};

ostream& operator<<(ostream& os, Ipv4& o) {
  return os << unsigned(o.getField(0)) << "."
            << unsigned(o.getField(1)) << "."
            << unsigned(o.getField(2)) << "."
            << unsigned(o.getField(3)) << endl;
}

int main(void) {
  Ipv4 ipv4;

  // 標準入力から数字を読み込み (最後以外は '.', 最後は '\n' がデリミタ)
  for (auto i = 0; i < Ipv4::numOfFields; i++) {
    char delim = (i == Ipv4::numOfFields - 1) ? '\n' : '.';
    string buf;
    getline(cin, buf, delim);

    // int に変換
    ipv4.setField(i, (uint8_t)stoi(buf));
  }
  cout << ipv4 << endl;
  return 0;
}
