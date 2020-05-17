#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> m(100010, 0LL);
    for (long long i = 0; i < N; i++)
    {
        long long a, b;
        cin >> a >> b;
        m[a] += b;
    }
    for (long long i = 1LL; i <= 100010LL; i++)
    {
        m[i] += m[i - 1LL];
    }
    for (long long i = 0LL; i <= 100009LL; i++)
    {
        if (m[i] < K && K <= m[i + 1LL])
            cout << i + 1LL << endl;
    }
    return 0;
}