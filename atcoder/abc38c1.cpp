#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long res = 0;
    int right = 1;
    for (int left = 0; left < n; left++) {
        while (right < n && (right <= left || a[right-1] < a[right])) {
            right++;
        }
        res += right-left;
        if (left == right) right++;
    }
    cout << res << endl;
    return 0;
}