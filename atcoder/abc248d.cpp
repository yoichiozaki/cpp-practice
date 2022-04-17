#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> pos(N + 1, vector<int>());
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        pos[x].push_back(i);
    }
    int Q; cin >> Q;
    for (int _ = 0; _ < Q; _++) {
        int l, r, x; cin >> l >> r >> x;
        cout << lower_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l - 1) << endl;
    }
    return 0;
}