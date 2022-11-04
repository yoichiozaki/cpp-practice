#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> H(N + 1);
    for (int i = 1; i <= N; i++) cin >> H[i];
    int ans = 1;
    for (int i = 2; i <= N; i++) {
        if (H[ans] < H[i])
            ans = i;
    }
    cout << ans << endl;
    return 0;
}