#include <bits/stdc++.h>

using namespace std;

bool is_valid(int h, int m) {
    return ((0 <= h) && (h <= 23)) && ((0 <= m) && (m <= 59));
}

bool check(int h, int m) {
    int A = h / 10, B = h % 10;
    int C = m / 10, D = m % 10;
    int AC = A * 10 + C;
    int BD = B * 10 + D;
    return is_valid(AC, BD);
}

int main() {
    int H, M; cin >> H >> M;
    while (!check(H, M)) {
        M += 1;
        if (M == 60) {
            H++;
            M = 0;
        }
        if (H == 24) {
            H = 0;
        }
    }
    cout << H << " " << M << endl;
    return 0;
}