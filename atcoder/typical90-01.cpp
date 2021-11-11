#include <bits/stdc++.h>

using namespace std;

int N, L, K;

bool check(vector<int> A, int ans)
{
    int count = 0, prev = 0;
    for (auto a : A)
    {
        if (ans <= a - prev && ans <= L - a)
        {
            count += 1;
            prev = a;
        }
    }
    if (K <= count)
        return true;
    return false;
}

int main()
{
    cin >> N >> L;
    cin >> K;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int ok = -1;
    int ng = L + 1;
    while (1 < abs(ok - ng))
    {
        int mid = ok + (ng - ok) / 2;
        if (check(A, mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;
    return 0;
}