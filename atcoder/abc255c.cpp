#include <bits/stdc++.h>

using namespace std;

int main() {
    long long X, A, D, N; cin >> X >> A >> D >> N;
    if (D < 0) {
        A = A + D * (N - 1);
        D = -D;
    }
    long long minimum = A;
    long long maximum  = A + D * (N - 1);
    if (minimum <= X && X <= maximum) {
        long long M = 0;
        if (D != 0) {
             M = (X - minimum) % D;
        }
        cout << min(M, D - M) << endl;
    }
    else if (X < minimum) {
        cout << minimum - X << endl;
    } else {
        cout << X - maximum << endl;
    }
    return 0;
}