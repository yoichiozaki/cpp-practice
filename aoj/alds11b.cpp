#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (0 < y) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}