#include <bits/stdc++.h>

using namespace std;

bool match(char a, char b) {
    return (a == '?' || b == '?' || a == b);
}

int main() {
    string S, T; cin >> S >> T;
    vector<int> pre(S.size() + 1, false), suf(S.size() + 1, false);
    pre[0] = true;
    for (int i = 0; i < T.size(); i++) {
        if (!match(S[i], T[i])) break;
        pre[i + 1] = true;
    }
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    suf[0] = true;
    for (int i = 0; i < T.size(); i++) {
        if (!match(S[i], T[i])) break;
        suf[i + 1] = true;
    }
    for (int i = 0; i <= T.size(); i++) {
        if (pre[i] && suf[T.size() - i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}