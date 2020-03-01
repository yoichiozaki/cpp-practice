#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll digit = 1;
    for (ll i = 2; i <= sqrt(N); i++) {
        if (N%i == 0) {
            digit = i;
        }
    }
    cout << to_string(N/digit).length() << endl;
    return 0;
}