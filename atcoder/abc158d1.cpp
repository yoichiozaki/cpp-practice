#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int q; cin >> q;
    string t;
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            swap(s, t);
        } else {
            int f; char c;
            cin >> f >> c;
            if (f == 1) {
                t += c;
            } else {
                s += c;
            }
        }
    }
    reverse(t.begin(), t.end());
    t += s;
    cout << t << endl;
    return 0;
}