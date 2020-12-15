#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int ans = accumulate(A.begin(), A.end(), 0, [](int m, int n) {
        return __gcd(m, n);
    });
    cout << ans << endl;
    return 0;
}