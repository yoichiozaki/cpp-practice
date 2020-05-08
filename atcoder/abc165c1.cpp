#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<long long> a, b, c, d;

long long score(vector<int> &A)
{
    long long res = 0;
    for (int i = 0; i < Q; i++)
    {
        if (A[b[i]] - A[a[i]] == c[i])
            res += d[i];
    }
    return res;
}

long long DFS(vector<int> &A)
{
    if (A.size() == N)
    {
        return score(A);
    }
    long long res = 0;
    int prev_last = (A.empty() ? 0 : A.back());
    for (int i = prev_last; i < M; i++)
    {
        A.push_back(i);
        res = max(res, DFS(A));
        A.pop_back();
    }
}

int main()
{
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for (int q = 0; q < Q; q++)
    {
        cin >> a[q] >> b[q] >> c[q] >> d[q];
        a[q]--;
        b[q]--;
    }
    vector<int> A;
    cout << DFS(A) << endl;
    return 0;
}