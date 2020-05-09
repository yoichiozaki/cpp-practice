#include <bits/stdc++.h>
using namespace std;

// 2辺固定して残り1辺を二分探索

int main()
{
    int N;
    cin >> N;
    vector<long long> L(N);
    for (int i = 0; i < N; i++)
        cin >> L[i];
    sort(L.begin(), L.end());

    long long cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();

            cnt += max(k - (j + 1), 0);
        }
    }
    cout << cnt << endl;
    return 0;
}