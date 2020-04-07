#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> S(n);

bool is_ok(int index, int key) {
    if (key <= S[index]) return true;
    else return false;
}

// key以上となる最小のindexを返す
int binary_search(int key) {
    int ng = -1;
    int ok = (int)S.size();
    while (1 < abs(ok - ng)) {
        int mid = (ok + ng) / 2;
        if (is_ok(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin >> n; S.resize(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    cin >> q;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << "binary_search(x): " << binary_search(x) << endl;
        if (0 <= binary_search(x) && binary_search(x) < n) cnt++;
    }
    cout << cnt << endl;
    return 0;
}