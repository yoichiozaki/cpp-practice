#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    int right = 0;
    set<int> nums;

    for (int left = 0; left < n; left++) {
        while (right < n && !nums.count(a[right])) {
            nums.insert(a[right]);
            right++;
        }
        res = max(res, right-left);
        if (left == right) right++;
        else nums.erase(a[left]);
    }

    cout << res << endl;
    return 0;
}