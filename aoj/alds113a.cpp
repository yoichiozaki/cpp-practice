#include <bits/stdc++.h>
using namespace std;

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2*N - 1], dneg[2*N - 1];
bool X[N][N];
void init() {
    for (int i = 0; i < N; i++) {
        row[i] = FREE;
        col[i] = FREE;
    }
    for (int i = 0; i < 2*N - 1; i++) {
        dpos[i] = FREE;
        dneg[i] = FREE;
    }
}
void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (X[i][j]) {
                if (row[i] != j) return;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ((row[i] == j) ? "Q" : ".");
        }
        cout << endl;
    }
}
void rec(int i) {
    if (i == N) {
        print_board();
        return;
    }
    for (int j = 0; j < N; j++) {
        if (col[j] == NOT_FREE ||
            dpos[i+j] == NOT_FREE ||
            dneg[i-j+N-1] == NOT_FREE) continue;
        row[i] = j; col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
        rec(i+1);
        row[i] = col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
    }
}

int main() {
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i][j] = false;
        }
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        X[r][c] = true;
    }
    rec(0);
    return 0;
}