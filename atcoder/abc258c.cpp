#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, Q; cin >> N >> Q;
    string S; cin >> S;
    long long P = 0;
    for (int i = 0; i < Q; i++) {
        long long q, x; cin >> q >> x;
        if (q == 1) {
            P += x;
        } else {
            cout << S[x - P % N - 1] << endl;
        }
    }
    return 0;
}