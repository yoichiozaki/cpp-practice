#include <bits/stdc++.h>

using namespace std;

int main() {
    long long L, N1, N2; cin >> L >> N1 >> N2;
    vector<pair<long long, long long>> A(N1), B(N2);
    for (long long i = 0; i < N1; i++) {
        long long v, l; cin >> v >> l;
        A[i] = make_pair(v, l);
    }
    for (long long i = 0; i < N2; i++) {
        long long v, l; cin >> v >> l;
        B[i] = make_pair(v, l);
    }
    long long i = 0, j = 0;
    long long pos1 = 0, pos2 = 0;
    long long ans = 0;
    while (i < N1 && j < N2) {
        if (A[i].first == B[j].first) {
            ans += min(pos1 + A[i].second, pos2 + B[j].second) - max(pos1, pos2);
        }
        if (pos1 + A[i].second < pos2 + B[j].second) {
            pos1 += A[i].second;
            i += 1;
        } else {
            pos2 += B[j].second;
            j += 1;
        }
    }
    cout << ans << endl;
    return 0;
}