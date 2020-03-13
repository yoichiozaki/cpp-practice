#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;

    for (int q = 0; q < Q; q++) {
        int n; cin >> n;
        long long x; cin >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int res = n+1; // rightの最大値

        int right = 0;
        long long sum = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && sum < x) {
                sum += a[right];
                right++;
            }

            if (sum < x) break;
            res = min(res, right - left);

            if (left == right) {
                right++;
            } else {
                sum -= a[left];
            }
        }

        if (res < n+1) {
            cout << res << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}