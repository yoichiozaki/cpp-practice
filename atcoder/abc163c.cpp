#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(200010);
    vector<int> ans(200010);
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) ans[a[i]]++;
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}