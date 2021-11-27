#include <bits/stdc++.h>

using namespace std;

struct BIT
{
    long long _size = 1LL;
    vector<long long> _bit;

    void init(long long sz)
    {
        _size = sz + 2LL;
        _bit.resize(_size + 2LL, 0LL);
    }
    void add(long long pos, long long x)
    {
        pos++;
        while (pos <= _size)
        {
            _bit[pos] += x;
            pos += (pos & -pos);
        }
    }
    long long sum(long long pos)
    {
        long long s = 0LL;
        pos++;
        while (pos >= 1LL)
        {
            s += _bit[pos];
            pos -= (pos & -pos);
        }
        return s;
    }
};

long long N, M;
long long L[1 << 18], R[1 << 18];
long long V1[1 << 18], V2[1 << 18], V3[1 << 18];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> L[i] >> R[i];

    long long case1 = 0;
    for (int i = 1; i <= M; i++)
        V3[L[i]] += 1;
    for (int i = 1; i <= M; i++)
        V3[R[i]] += 1;
    for (int i = 1; i <= N; i++)
        case1 += V3[i] * (V3[i] - 1LL) / 2LL;

    long long case2 = 0;
    for (int i = 1; i <= M; i++)
        V1[R[i]] += 1;
    for (int i = 1; i <= M; i++)
        V2[L[i] - 1] += 1;
    for (int i = 1; i <= N; i++)
        V1[i] += V1[i - 1];
    for (int i = 1; i <= N; i++)
        case2 += V1[i] * V2[i];

    vector<pair<long long, long long>> vec;
    for (int i = 1; i <= M; i++)
        vec.push_back(make_pair(R[i], L[i]));
    sort(vec.begin(), vec.end());

    long long case3 = 0;
    BIT t;
    t.init(N + 2);
    for (int i = 0; i < vec.size(); i++)
    {
        long long left = vec[i].second, right = vec[i].first;
        long long ret = t.sum(right) - t.sum(left);
        case3 += ret;
        t.add(left, 1LL);
    }

    long long others = case1 + case2 + case3;
    cout << M * (M - 1LL) / 2LL - others << endl;
    return 0;
}