#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, S, ans = 0;
    cin >> K >> S;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            if (0 <= S-x-y && S-x-y <= K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}