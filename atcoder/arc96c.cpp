#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long mincost = 1e9;
    for (long long i = 0; i <= 100000; i++) {
        long long c = i*2LL*C + max(0LL, X-i)*A + max(0LL, Y-i)*B;
        if (c < mincost) {
            mincost = c;
        }
    }
    cout << mincost << endl;
    return 0;
}