#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, W; cin >> N >> W;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> flag(W + 1);
    for (int i = 0; i < N; i++) {
        int s = A[i];
        if (s <= W) flag[s] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int s = A[i] + A[j];
            if (s <= W) flag[s] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int s = A[i] + A[j] + A[k];
                if (s <= W) flag[s] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= W; i++) {
        ans += flag[i];
    }
    cout << ans << endl;
    return 0;
}