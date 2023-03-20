#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> gone(N + 1);
    int ans = 1;
    while (Q--) {
        int event; cin >> event;
        if (event == 1) {
            continue;
        } else if (event == 2) {
            int x; cin >> x;
            gone[x] = 1;
        } else {
            while (gone[ans]) ans++;
            cout << ans << endl;
        }
    }
    return 0;
}