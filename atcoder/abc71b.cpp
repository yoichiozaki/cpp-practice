#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> alphabet(26, 0);
    for (int i = 0; i < (int)s.size(); i++) {
        alphabet.at(s[i] - 'a')++;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}