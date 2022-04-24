#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    bool UPPERCASE = false;
    bool lowercase = false;
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') UPPERCASE = true;
        else lowercase = true;
    }
    bool nodups = true;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i+1]) {
            nodups = false;
            break;
        }
    }
    if (UPPERCASE && lowercase && nodups) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}