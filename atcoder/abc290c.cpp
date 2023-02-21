#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        S.insert(a);
    }
    for (int i = 0; i < K; i++) {
        if (S.find(i) == S.end()) {
            cout << i << endl;
            return 0;
        }
    }
    cout << K << endl;
    return 0;
}