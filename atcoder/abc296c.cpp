#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int i = 0;
    for (int j = 0; j < N; j++) {
        while (i < N && A[i] - A[j] < X) {
            i++;
        }
        if (i < N && A[i] - A[j] == X) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}