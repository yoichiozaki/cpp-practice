#include <bits/stdc++.h>
using namespace std;

int main() {
    long long H, W; cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << 1 << endl;
    } else {
        cout << (H*W + 1) / 2 << endl;
    }
    return 0;
}