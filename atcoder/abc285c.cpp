#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    reverse(S.begin(), S.end());
    long long base = 1;
    long long ans = 0;
    for (int i = 0; i < S.size(); i++) {
        ans += base * (long long)(S[i] - 'A' + 1);
        base *= 26;
    }
    cout << ans << endl;
    return 0;
}