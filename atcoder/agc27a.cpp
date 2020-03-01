#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    while (x) {
        if (N <= ans || x < a.at(ans) ) {
            break;
        }
        x -= a.at(ans);
        ans++;
    }
    if (N <= ans && x != 0) {
        ans--;
    }
    cout << ans << endl;
}