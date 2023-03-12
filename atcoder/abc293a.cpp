#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    for (int i = 1; i <= S.length() / 2; i++) {
        cout << S[2 * i - 1] << S[2 * i - 2];
    }
    cout << endl;
    return 0;
}