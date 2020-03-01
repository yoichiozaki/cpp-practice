#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 1, N;
    cin >> N;
    while (ans <= N) {
        ans *= 2;
    }
    ans /= 2;
    cout << ans << endl;
}