#include <bits/stdc++.h>
using namespace std;

// 名前空間A
namespace A {
  void f() {
    cout << "namespace A" << endl;
  }
  namespace AA {
      void g() {
          cout << "namespace AA" << endl;
      }
  }
}
// 名前空間B
namespace B {
  void f() {
    cout << "namespace B" << endl;
  }
}

int main() {
  namespace aaa = A::AA;
  // namespace a3 = A::AA;
  A::f();  // 名前空間A内の関数fの呼び出し
  A::AA::g();
  B::f();  // 名前空間B内の関数fの呼び出し
}

