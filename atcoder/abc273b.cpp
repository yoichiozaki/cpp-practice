#include <bits/stdc++.h>

using namespace std;

int main() {
    long long X, K; cin >> X >> K;
    long long base = 1;
    for (long long  i = 0; i < K; i++) {
        X /= base;
        if (X % 10 <= 4) X -= X % 10;
        else X += (10 - X % 10);
        X *= base;
        base *= 10;
    }
    cout << X << endl;
    return 0;
}