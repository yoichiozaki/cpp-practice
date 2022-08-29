#include <bits/stdc++.h>

using namespace std;

int X[4], Y[4];

int f0(int x, int y) {
    return (X[2] - X[0]) * (y - Y[0]) - (Y[2] - Y[0]) * (x - X[0]);
}

int f1(int x, int y) {
    return (X[3] - X[1]) * (y - Y[1]) - (Y[3] - Y[1]) * (x - X[1]);
}

int sgn(int x) {
    if (x == 0) return 0;
    return x / abs(x);
}

int main() {
    for (int i = 0; i < 4; i++) cin >> X[i] >> Y[i];
    if (sgn(f0(X[1], Y[1])) != sgn(f0(X[3], Y[3])) && sgn(f1(X[0], Y[0])) != sgn(f1(X[2], Y[2]))) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}