#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y, N; cin >> X >> Y >> N;
    if (X * 3 > Y) cout << (N / 3) * Y + (N % 3) * X << endl;
    else cout << X * N << endl;
    return 0;
}