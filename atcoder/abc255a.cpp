#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C; cin >> R >> C;
    R--, C--;
    int A[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }
    cout << A[R][C] << endl;
    return 0;
}