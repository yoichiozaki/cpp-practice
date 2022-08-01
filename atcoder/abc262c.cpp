#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int same = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        if (A[i] == i) same++;
    }
    long long ans = (long long)same * (same - 1) / 2;
    for (int i = 0; i < N; i++) {
        if (i < A[i] && A[A[i]] == i) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}