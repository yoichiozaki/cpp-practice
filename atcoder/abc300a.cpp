#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A, B; cin >> N >> A >> B;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    int ans;
    for (int i = 0; i < N; i++) {
        if (A + B == C[i]) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}