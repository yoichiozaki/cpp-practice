#include <bits/stdc++.h>
using namespace std;

int main() {
    // 2進数表記したときの1の個数
    long long x;
    cin >> x;
    cout << __builtin_popcountll(x) << endl;
    return 0;
}