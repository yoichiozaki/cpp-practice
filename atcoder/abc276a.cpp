#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    for (int i = S.size(); 1 <= i; i--) {
        if (S[i-1] == 'a') {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}