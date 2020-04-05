#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int len = 0;
    int maxlen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            len += 1;
            maxlen = max(maxlen, len);
        } else {
            len = 0;
        }
    }
    cout << maxlen << endl;
    return 0;
}