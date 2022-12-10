#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> accum(N, 0);
    for (int i = 0; i < N; i++) cin >> accum[i];
    vector<int> ans(N, 0);
    for (int i = N - 1; 0 < i; i--) {
        ans[i] = accum[i] - accum[i - 1];
    }
    ans[0] = accum[0];
    for (int i = 0; i < N; i++) {
        if (i != N - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
    return 0;
}