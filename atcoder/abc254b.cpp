#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        A[i] = vector<int>(i + 1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                A[i][j] = 1;
            } else {
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j != 0) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}