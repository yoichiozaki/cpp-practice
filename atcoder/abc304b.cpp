#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    if (S.size() <= 3) cout << S << endl;
    else cout << S.substr(0, 3) << string(S.size() - 3, '0') << endl;
    return 0;
}