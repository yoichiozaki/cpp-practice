#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    int ans = 0;
    for (char c: S) {
        if (c == 'v') ans += 1;
        else ans += 2;
    }
    cout << ans << endl;
    return 0;
}