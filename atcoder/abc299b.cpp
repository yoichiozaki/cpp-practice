#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T; cin >> N >> T;
    int c[200001], r[200001];

    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= N; i++) cin >> r[i];

    pair<int, int> tmax = {-1, -1}, lmax = {-1, -1};
    for (int i = 1; i <= N; i++) {
        if (c[i] == T) tmax = max(tmax, {r[i], i});
        if (c[i] == c[1]) lmax = max(lmax, {r[i], i});
    }
    if (tmax.first != -1) cout << tmax.second << endl;
    else cout << lmax.second << endl;
    return 0;
}