#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;

int N, M, D;

bool is_ok(vector<int> X, vector<int> V, int D, int minimum_value)
{
    int prev_pos = -inf;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (V[i] < minimum_value)
            continue;
        if (D <= X[i] - prev_pos)
        {
            prev_pos = X[i];
            cnt += 1;
        }
    }
    if (M <= cnt)
        return true;
    else
        return false;
}

int binary_search(vector<int> X, vector<int> V, int D)
{
    int ng = inf;
    int ok = -1;
    while (1 < abs(ok - ng))
    {
        int mid = (ok + ng) / 2;
        if (is_ok(X, V, D, mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }

    return ok;
}

int main()
{
    cin >> N >> M >> D;
    vector<int> X(N + 5, 0);
    vector<int> V(N + 5, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i] >> V[i];
    }

    vector<pair<int, int>> pics;
    for (int i = 1; i <= N; i++)
    {
        pics.push_back(make_pair(X[i], V[i]));
    }
    sort(pics.begin(), pics.end());
    for (int i = 1; i <= N; i++)
    {
        X[i] = pics[i - 1].first;
        V[i] = pics[i - 1].second;
    }

    cout << binary_search(X, V, D) << endl;
    return 0;
}