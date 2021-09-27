#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    long long X;
    cin >> X;
    long long sum = 0;
    for (auto a : A)
        sum += a;
    long long P = X / sum;
    long long sumb = P * sum;
    long long ans = P * N;
    for (auto a : A)
    {
        sumb += a;
        ans += 1;
        if (X < sumb)
        {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}