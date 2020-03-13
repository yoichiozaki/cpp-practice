#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) {
        if (a[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int ans = 0;
    int right = 0;
    long long mul = 1;
    for (int left = 0; left < N; left++) {
        while (right < N && mul * a[right] <= K) {
            mul *= a[right];
            right++;
        }
        ans = max(ans, right - left);
        if (left == right) {
            right++;
        } else {
            mul /= a[left];
        }
    }
    cout << ans << endl;
    return 0;
}