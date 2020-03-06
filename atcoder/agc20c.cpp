#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 4000000;

ll n, sum;
bitset<M+5> v;
int main() {
    cin >> n;
    v[0] = 1;
    while (--n) {
        ll t;
        cin >> t;
        sum += t;
        v |= (v << t);
    }
    for (ll i = (sum+1)/2; i <= sum; i++) {
        if (v[i]) {
            cout << i << endl;
            return 0;
        } else {
        }
    }
    return 0;
}