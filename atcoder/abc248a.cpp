#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    sort(S.begin(), S.end());
    for (int i = 0; i < 10; i++) {
        if (S[i] != (char)('0' + i)) {
            cout << (char)('0' + i) << endl;
            return 0;
        }
    }
    return 0;
}