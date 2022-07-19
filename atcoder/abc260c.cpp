#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, X, Y;
    cin >> N >> X >> Y;
    long long reds[12], blues[12];
    reds[1] = 0, blues[1] = 1;
    for (int i = 2; i <= N; i++) {
        blues[i] = reds[i - 1] + blues[i - 1] * Y;
        reds[i] = reds[i - 1] + blues[i] * X;
    }
    cout << reds[N] << endl;
    return 0;
}