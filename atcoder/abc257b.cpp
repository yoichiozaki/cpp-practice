#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    int A[201];
    for (int i = 1; i <= K; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) {
        int X; cin >> X;
        if (A[X] == N) continue;
        else if (X == K) A[X] += 1;
        else if (A[X] + 1 < A[X + 1]) A[X] += 1;
    }
    for (int i = 1; i <= K; i++) {
        cout << A[i];
        if (i < K) cout << " ";
        else cout << endl;
    }
    return 0;
}