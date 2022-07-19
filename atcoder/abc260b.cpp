#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<int> A(N + 5), B(N + 5);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    vector<bool> passed(N + 5, false);
    vector<int> C;
    for (int i = 1; i <= N; i++) {
        C.push_back(10000 * (100 - A[i]) + i);
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < X; i++) {
        passed[C[i] % 10000] = true;
    }
    C.clear();
    for (int i = 1; i <= N; i++) {
        if (!passed[i]) {
            C.push_back(10000 * (100 - B[i]) + i);
        }
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < Y; i++) {
        passed[C[i] % 10000] = true;
    }
    C.clear();
    for (int i = 1; i <= N; i++) {
        if (!passed[i]) {
            C.push_back(10000 * (200 - A[i] - B[i]) + i);
        }
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < Z; i++) {
        passed[C[i] % 10000] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (passed[i]) {
            cout << i << endl;
        }
    }
    return 0;
}