#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<string> A;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        if (i < K) A.push_back(S);
    }
    sort(A.begin(), A.end());
    for (string S : A) cout << S << endl;
    return 0;
}