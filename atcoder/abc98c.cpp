#include <bits/stdc++.h>
using namespace std;

// リーダーのいる方向を向く

int main() {
    int n;
    string s;
    cin >> n >> s;
    int sol = 1e9;
    int ct = 0;
    for (int i = 1; i < n; i++) {
        ct += (s[i] == 'E');
    }
    for (int i = 0; i < n; i++) {
        sol = min(sol, ct);
        if (i + 1 < n) {
            ct += (s[i] == 'W');
            ct -= (s[i + 1] == 'E');
        }
    }
    cout << sol;
    return 0;
}
