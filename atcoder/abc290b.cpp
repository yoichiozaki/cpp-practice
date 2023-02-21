#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    for (auto &nx : S) {
        if (nx == 'o') {
            if (K <= 0) nx = 'x';
            K--;
        }
    }
    cout << S << endl;
    return 0;
}