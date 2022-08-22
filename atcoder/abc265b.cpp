#include <bits/stdc++.h>

using namespace std;

int A[100010];
int bonus[100010];
int main() {
    int N, M;
    long long T;
    cin >> N >> M >> T;
    for (int i = 1; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) {
        int X, Y; cin >> X >> Y;
        bonus[X] = Y;
    }
    for (int i = 1; i < N; i++) {
        if (T <= A[i]) {
            cout << "No" << endl;
            return 0;
        }
        T -= A[i];
        T += bonus[i + 1];
    }
    cout << "Yes" << endl;
    return 0;
}