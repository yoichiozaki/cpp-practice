#include <bits/stdc++.h>

using namespace std;

int main() {
    long long X; cin >> X;
    vector<long long> ans;
    for (long long i = (1LL << 60) - 1; 0 <= i; i--) {
        i &= X;
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for (auto &nx : ans) {
        cout << nx << endl;
    }
    return 0;
}