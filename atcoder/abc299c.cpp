#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned N; cin >> N;
    string S; cin >> S;

    unsigned ans{};
    for (unsigned flip{}; flip < 2; flip++) {
        unsigned level{};
        for (unsigned int i = 0; i < N; i++) {
            if (S[i] == '-') {
                ans = max(ans, level);
                level = 0;
            } else {
                level += 1;
            }
        }
        reverse(S.begin(), S.end());
    }

    if (ans) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}