#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N), T(M);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int j = 0; j < M; j++) cin >> T[j];
    sort(T.begin(), T.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (binary_search(T.begin(), T.end(), S[i].substr(3))) ans += 1;
    }
    cout << ans << endl;
    return 0;
}