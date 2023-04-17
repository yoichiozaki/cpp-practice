#include <bits/stdc++.h>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;
    long long ans = 0;
    if (A < B) swap(A, B);
    while (B > 0) {
        ans += A / B;
        A %= B;
        swap(A, B);
    }
    cout << ans - 1 << endl;
    return 0;
}