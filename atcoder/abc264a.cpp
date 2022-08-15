#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, R; cin >> L >> R; L--, R--;
    string S = "atcoder";
    for (int i = L; i <= R; i++) cout << S[i];
    cout << endl;
    return 0;
}