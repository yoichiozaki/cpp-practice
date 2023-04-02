#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> field(8);
    for (int i = 0; i < 8; i++) cin >> field[i];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == '*') {
                cout << "abcdefgh"[j] << 8 - i << endl;
                return 0;
            }
        }
    }
    return 0;
}