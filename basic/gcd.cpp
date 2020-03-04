#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << "最大公約数: " << __gcd(a, b) << endl;
    cout << "最小公倍数: " << a/__gcd(a, b) * b << endl;
   return 0;
}