#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<pair<int, char>> table;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int W; cin >> W;
        table.push_back({W, S[i]});
        if (S[i] == '1') ans += 1;

    }
    sort(table.begin(), table.end());
    int W = ans;
    for (int i = 0; i < N; i++) {
        if (table[i].second == '1') W -= 1;
        else W += 1;
        if (i < N - 1) {
            if (table[i].first != table[i + 1].first) ans = max(ans, W);
        }
        else {
            ans = max(ans, W);
        }
    }
    cout << ans << endl;
    return 0;
}