#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    bool c1 = (S.rfind('B') - S.find('B')) % 2 == 1;
    bool c2 = (S.find('R') < S.find('K')) && (S.find('K') < S.rfind('R'));
    if (c1 && c2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}