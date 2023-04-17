#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    for (int i = 0; i < H; i++) {
        string S; cin >> S;
        for (int j = 0; j < W - 1; j++) {
            if (S[j] == 'T' && S[j + 1] == 'T') {
                S[j] = 'P';
                S[j + 1] = 'C';
            }
        }
        cout << S << endl;
    }
    return 0;
}