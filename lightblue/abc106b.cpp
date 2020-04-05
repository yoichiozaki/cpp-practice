#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    int div = 0;
    for (int i = 1; i <= n; i++) {
        if (n%i == 0) div++;
    }
    return n%2 == 1 && div == 8;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (check(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}