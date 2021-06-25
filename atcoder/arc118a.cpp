#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, N;
    cin >> t >> N;
    vector<bool> used(101010);
    for (long long i = 1; i < 100 + t + 1; i++)
    {
        long long num = (100 * i + t * i) / 100;
        used[num] = true;
    }
    vector<long long> candidates;
    for (long long i = 1; i < 100 + t + 1; i++)
    {
        if (!used[i])
            candidates.push_back(i);
    }
    long long cycle_len = 100 + t;
    long long candidate_len = candidates.size();
    N -= 1;
    long long repeat = N / candidate_len;
    long long ans = repeat * cycle_len + candidates[(N % candidate_len)];
    cout << ans << endl;
    return 0;
}