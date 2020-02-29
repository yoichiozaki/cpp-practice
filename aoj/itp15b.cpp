#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    while(1) {
        cin >> H >> W;
        if (H == 0 && W == 0) {
            break;
        }
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (1 <= h && h <= H-2 && 1 <= w && w <= W-2) {
                    cout << ".";
                } else {
                    cout << "#";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}