#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    deque<char> deq;
    for (char c : s) {
        deq.push_back(c);
    }
    bool flip = false;
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type; cin >> type;
        if (type == 1) {
            flip = !flip; // 左右反転
        } else {
            int f; char c;
            cin >> f >> c;
            if (flip) {
                f = 3-f;
            }
            if (f == 1) {
                deq.push_front(c);
            } else {
                deq.push_back(c);
            }
        }
    }
    if (flip) {
        reverse(deq.begin(), deq.end());
    }
    string ans;
    for (char c : deq) {
        ans += c;
    }
    cout << ans << endl;
}