#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    P--, Q--, R--, S--;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = P; i <= Q; i++) {
        swap(A[i], A[R + (i - P)]);
    }
    for (int i = 0; i < N; i++) {
        if (i != N - 1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
    return 0;
}