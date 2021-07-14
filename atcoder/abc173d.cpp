#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end(), greater<long long>());

    long long ans = A[0];
    for (int i = 0; i < N - 2; i++)
        ans += A[i / 2 + 1];
    cout << ans << endl;
    return 0;
}