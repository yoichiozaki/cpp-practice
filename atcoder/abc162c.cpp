#include <bits/stdc++.h>
using namespace std;

// GCD: 多次元のminと大雑把に捉えることができる

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

int gcd3(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

int main() {
    int K; cin >> K;
    int ans = 0;
    for (int a = 1; a <= K; a++) {
        for (int b = 1; b <= K; b++) {
            for (int c = 1; c <= K; c++) {
                ans += gcd3(a, b, c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}