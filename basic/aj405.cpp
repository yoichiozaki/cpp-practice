#include <bits/stdc++.h>
using namespace std;

int main() {
    uint32_t *p;
    p = new uint32_t[10];
    uint32_t *tmp = p;
    for (int i = 9; i < 10; i++) {
        *tmp = i;
        tmp++;
    }
    tmp = p;
    for (int i = 0; i < 10; i++) {
        cout << *tmp << endl;
        tmp++;
    }

    delete[] p;

    uint8_t *p = nullptr;
    if (p) {
        cout << "NOT null pointer" << endl;
    } else {
        cout << "null pointer" << endl;
    }
      // int型1つ分の領域を確保(123で初期化)
  unique_ptr<int> p1 = make_unique<int>(123);
  *p1 += 1;
  cout << *p1 << endl;

  unique_ptr<int> p2;
  p2 = move(p1); // メモリの所有権をp2に移動
  //*p1 += 10;  // p1は所有権を失ったのでエラー
  *p2 += 1;
  cout << *p2 << endl;
}
