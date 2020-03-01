#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, m;
    cin >> N >> X;
    vector<int> ms(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> m;
        ms.at(i) = m;
        X -= m;
    }
    sort(ms.begin(), ms.end());
    cout << N + X/ms[0] << endl;
}