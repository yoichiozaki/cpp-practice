#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    for (char c : S) {
        if (c == '0') cout << '1';
        else cout << '0';
    }
    cout << endl;
    return 0;
}