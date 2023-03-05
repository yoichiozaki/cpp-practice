#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    string T = "";
    for (auto ch : S) {
        T += toupper(ch);
    }
    cout << T << endl;
    return 0;
}