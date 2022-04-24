#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, int c, int x) {
    int q = x / (a + c);
    int r = x % (a + c);
    return (q * a + min(a, r)) * b;
}

int main() {
    int A, B, C, D, E, F, X; cin >> A >> B >> C >> D >> E >> F >> X;
    int takahashi = calc(A, B, C, X);
    int aoki = calc(D, E, F, X);
    if (takahashi > aoki) cout << "Takahashi" << endl;
    else if (takahashi < aoki) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}