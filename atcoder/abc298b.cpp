#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> A) {
    int N = A.size();
    vector<vector<int>> rotated(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - 1 - i] = A[i][j];
        }
    }
    return rotated;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }
    for (int _ = 0; _ < 4; _++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 1 && B[i][j] == 0) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
        A = rotate90(A);
    }
    cout << "No" << endl;
    return 0;
}