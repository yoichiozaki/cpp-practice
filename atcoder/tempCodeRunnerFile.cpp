#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> csum;
    csum.push_back(0LL);
    long long total = 0LL;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        total += a;
        csum.push_back(total);
    }

    long long cnt = 0LL;
    for (int i = 0; i < N; i++)
    {
        cnt += csum.end() - lower_bound(csum.begin() + i + 1, csum.end(), csum[i] + K);
    }
    cout << cnt << endl;
    return 0;
}