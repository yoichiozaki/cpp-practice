#include <bits/stdc++.h>
using namespace std;

const unsigned long long MOD = 1000000007;

int main(){
    unsigned long long N;
    cin >> N;
    unsigned long long ans = 1;
    for (unsigned long long i = 1; i <= N; i++) {
        ans *= i;
        if (MOD < ans) {
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
