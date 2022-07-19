#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    map<char, int> table;
    for (auto &ch: S) {
        table[ch] += 1;
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (table[ch] == 1) {
            cout << ch << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}