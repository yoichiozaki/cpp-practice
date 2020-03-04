#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int c = 1; c <= N; c+= 2) {
        int n_divisors = 0;
        for (int x = 1; x <= c; x++) {
            if (c%x == 0) {
                n_divisors++;
            }
        }
        if (n_divisors == 8) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}