#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N, 0LL);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    long long ans = 0;
    long long tmp_max = A[0];
    for (int i = 1; i < N; i++)
    {
        if (A[i] < tmp_max)
            ans += (tmp_max - A[i]);
        else
            tmp_max = A[i];
    }
    cout << ans << endl;
    return 0;
}