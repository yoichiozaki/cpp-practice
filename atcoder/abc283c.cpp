#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    int ans = 0;
    while (!S.empty()) {
        const auto back{S.back()};
        S.pop_back();
        if (back == '0' && S.back() == '0') S.pop_back();
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}