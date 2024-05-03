#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, H, K; cin >> N >> M >> H >> K;
    string S; cin >> S;
    set<pair<int, int>> st;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        st.insert({x, y});
    }
    int nx = 0, ny = 0;
    for (int i = 0; i < N; i++) {
        int dx = 0, dy = 0;
        if (S[i] == 'R') dx = 1;
        if (S[i] == 'L') dx = -1;
        if (S[i] == 'U') dy = 1;
        if (S[i] == 'D') dy = -1;
        nx += dx, ny += dy;
        if (--H < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (H < K and st.count({nx, ny})) {
            H = K;
            st.erase({nx, ny});
        }
    }
    cout << "Yes" << endl;
    return 0;
}