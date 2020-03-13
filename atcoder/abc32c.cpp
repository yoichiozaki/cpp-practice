#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 数列aの中に0が含まれていれば全部かけてもK以下を満たすので数列の長さを返す
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << n << endl;
            return 0;
        }
    }

    int res = 0;
    int right = 0;
    long long mul = 1;
    for (int left = 0; left < n; left++) {
        while (right < n && mul * a[right] <= K) {
            mul *= a[right];
            right++;
        }
        res = max(res, right - left);
        if (left == right) {
            right++;
        } else {
            mul /= a[left];
        }
    }
    cout << res << endl;
    return 0;
}