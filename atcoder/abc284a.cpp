#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = N - 1; -1 < i; i--) cout << S[i] << endl;
    return 0;
}