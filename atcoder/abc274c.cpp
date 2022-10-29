#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> ans(2 * N + 1, 0);
    for (int i = 0; i < N; i++) {
        ans[2 * i + 1] = ans[A[i] - 1] + 1;
        ans[2 * i + 2] = ans[A[i] - 1] + 1;
    }
    for (int i = 0; i < 2 *N + 1; i++) cout << ans[i] << endl;
    return 0;
}