#include <bits/stdc++.h>

using namespace std;

int main() {
    long long A, B, K; cin >> A >> B >> K;
    int ans = 0;
    while (A < B) {
        A *= K;
        ans++;
    }
    cout << ans << endl;
    return 0;
}