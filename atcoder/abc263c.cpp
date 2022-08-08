#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A;
    for (int i = 0; i < N; i++) A.push_back(0);
    for (int i = 0; i < M - N; i++) A.push_back(1);
    do {
        for (int i = 0; i < M; i++) {
            if (A[i] == 0) cout << i + 1 << " ";
        }
        cout << endl;
    } while (next_permutation(A.begin(), A.end()));
    return 0;
}