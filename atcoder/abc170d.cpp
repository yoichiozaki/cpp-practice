#include <bits/stdc++.h>
using namespace std;

// エラトステネスの篩的なことを配列に対して行う

const int M = 1000005;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<int> cnt(M, 0);
    for (int x : A)
    {
        if (cnt[x] != 0)
        {
            cnt[x] = 2; // 同じ値について同じことを繰り返さないように2をマーク
            continue;
        }
        for (int i = x; i < M; i += x)
            cnt[i]++; // xの倍数をマークする
    }

    int ans = 0;
    for (int x : A)
    {
        if (cnt[x] == 1)
            ans++;
    }

    cout << ans << endl;
    return 0;
}