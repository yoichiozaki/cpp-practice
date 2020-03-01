#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, N; cin >> W >> H >> N;
    int x, y, a;
    vector<int> w = {0, W};
    vector<int> h = {0, H};
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> a;
        if (a == 1) {
            w.at(0) = max(w.at(0), x);
        } else if (a == 2) {
            w.at(1) = min(w.at(1), x);
        } else if (a == 3) {
            h.at(0) = max(h.at(0), y);
        } else if (a == 4) {
            h.at(1) = min(h.at(1), y);
        }
    }
    if (w.at(1)-w.at(0) > 0 && h.at(1) - h.at(0) > 0) {
        cout << (w.at(1)-w.at(0))*(h.at(1)-h.at(0)) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}