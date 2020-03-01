#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N, 0LL);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    cout << (int)abs(*prev(a.end()) - *a.begin()) << endl;
}