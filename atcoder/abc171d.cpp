#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> cnt(100005, 0);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    long long total = 0LL;
    for (int i = 0; i < 100005; i++)
        total += i * cnt[i];

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int B, C;
        cin >> B >> C;
        total += (C - B) * cnt[B];
        cnt[C] += cnt[B];
        cnt[B] = 0;
        cout << total << endl;
    }
    return 0;
}