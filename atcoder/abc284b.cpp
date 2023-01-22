#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        int ans = 0;
        for (int j = 0; j < N; j++) {
            int A; cin >> A;
            if (A % 2 == 1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}