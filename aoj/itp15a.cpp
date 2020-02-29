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
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}