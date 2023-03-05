#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> is_out(N + 1), yellow(N + 1);
    for (int i = 0; i < Q; i++) {
        int cmd, x; cin >> cmd >> x;
        if (cmd == 1) {
            yellow[x]++;
            if (yellow[x] == 2) {
                is_out[x] = 1;
            } 
        } else if (cmd == 2) {
            is_out[x] = 1;
        } else {
            cout << (is_out[x] ? "Yes" : "No") << endl;
        }
    }
    return 0;
}