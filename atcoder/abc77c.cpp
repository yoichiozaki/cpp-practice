#include <bits/stdc++.h>
using namespace std;

// A_i < B_j < C_kをみたす(i, j, k)の組を数える
// B_j(つまりj)を固定すれば，
// A_i < B_jを満たすiの個数とB_j < C_kを満たすkの個数の積
// これを全てのjに対して和を取る

using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> A(N, 0), B(N, 0), C(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> C.at(i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    for (int j = 0; j < N; j++) {
        ll ai = lower_bound(A.begin(), A.end(), B.at(j)) - A.begin();
        ll ck = C.end() - upper_bound(C.begin(), C.end(), B.at(j));
        ans += ai*ck;
    }
    cout << ans << endl;
    return 0;
}