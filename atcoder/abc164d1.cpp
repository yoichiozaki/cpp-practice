#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.size();
    vector<long long> v(2019, 0);
    long long fac = 1;
    long long current = 0;
    v[current]++;
    for (int i = 0; i < N; i++)
    {
        long long d = S[N - 1 - i] - '0';
        current = (current + fac * d) % 2019;
        fac = (fac * 10) % 2019;
        v[current]++;
    }
    long long res = 0;
    for (int i = 0; i < 2019; i++)
    {
        res += v[i] * (v[i] - 1) / 2;
    }
    cout << res << endl;
    return 0;
}