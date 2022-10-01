#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int C = A | B;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (C & (1 << i)) {
            ans += (1 << i);
        }
    }
    cout << ans << endl;
    return 0;
}