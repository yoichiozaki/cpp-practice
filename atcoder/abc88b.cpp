#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end(), greater<int>());
    int alice = 0, bob = 0;
    for (int i = 0; i < N; i++) {
        if (i%2 == 0) {
            alice += a.at(i);
        } else {
            bob += a.at(i);
        }
    }
    cout << alice - bob << endl;
    return 0;
}