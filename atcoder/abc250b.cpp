#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A, B; cin >> N >> A >> B;
    vector<string> field(A * N, string(B * N, ' '));
    for (int i = 0; i < A * N; i++) {
        for (int j = 0; j < B * N; j++) {
            if ((i / A + j / B) % 2 == 0) field[i][j] = '.';
            else field[i][j] = '#';
        }
    }
    for (auto line : field) cout << line << endl;
    return 0;
}