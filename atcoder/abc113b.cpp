#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, A;
    cin >> N >> T >> A;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H.at(i);
    int min = 1001001;
    int ans;
    for (int i = 0; i < N; i++) {
        int tmp = T*1000 - H.at(i)*6 - A*1000;
        if (tmp < 0) tmp = -tmp;
        if (tmp < min) {
            min = tmp;
            ans = i+1;
        }
    }
    cout << ans << endl;
}