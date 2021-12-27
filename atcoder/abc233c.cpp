#include <bits/stdc++.h>

using namespace std;

// 樹形図を深さ優先探索

long long ans = 0;
long long N, X;
vector<vector<long long>> A;

void dfs(long long bag, long long sofar)
{
    if (bag == N)
    {
        if (sofar == X)
            ans++;
        return;
    }
    for (long long ball : A[bag])
    {
        if (sofar * ball > X)
            continue; // 積がXを超えちゃうのでそれ以降は調べない
        dfs(bag + 1, sofar * ball);
    }
}

int main()
{
    cin >> N >> X;
    A.resize(N);
    for (long long i = 0; i < N; i++)
    {
        long long L;
        cin >> L;
        A[i].resize(L);
        for (long long j = 0; j < L; j++)
            cin >> A[i][j];
    }

    dfs(0, 1);

    cout << ans << endl;
    return 0;
}