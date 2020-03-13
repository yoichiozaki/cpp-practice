#include <bits/stdc++.h>
using namespace std;

int main() {
    int MAX = 101010;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) continue; // すでにiは素数でない判定が下っているのでスルー
        for (int j = i*2; j < MAX; j += i) {
            is_prime[j] = 0; // jはiの倍数なので素数ではない
        }
    }

    vector<int> a(MAX, 0); // 「2017-like」か
    for (int i = 0; i < MAX; i++) {
        if (i%2 == 0) continue;
        if (is_prime[i] && is_prime[(i+1)/2]) {
            a[i] = 1;
        }
    }

    vector<int> s(MAX+1, 0);
    for (int i = 0; i < MAX; i++) {
        s[i+1] = s[i] + a[i];
    }

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r;
        r++;
        cout << s[r] - s[l] << endl;
    }
    return 0;
}