#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n; cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(a[0] + k);
    int l = 0;
    for (int i = 0; i < n; i++) {
        l = max(l, a[i+1] - a[i]);
    }
    cout << k - l << endl;
    return 0;
}