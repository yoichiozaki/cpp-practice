#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M), C(N + M);
    map<int, int> pos;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    for (int i = 0; i < N + M; i++) {
        if (i < N) C[i] = A[i];
        else C[i] = B[i - N];
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < C.size(); i++) {
        pos[C[i]] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << pos[A[i]];
        if (i != N - 1) cout << " ";
        else cout << endl;
    }
    for (int i = 0; i < M; i++) {
        cout << pos[B[i]];
        if (i != M - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}