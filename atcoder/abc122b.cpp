#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> code = {'A', 'C', 'G', 'T'};
    string S; cin >> S;
    int maxlen = 0;
    int len = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (0 < code.count(S.at(i))) {
            len++;
            maxlen = max(maxlen, len);
        } else {
            len = 0;
        }
    }
    cout << maxlen << endl;
    return 0;
}