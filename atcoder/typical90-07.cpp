#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000000;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int Q;
    cin >> Q;
    vector<int> B(Q, 0);
    for (int i = 0; i < Q; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    for (auto b : B)
    {
        int c1 = lower_bound(A.begin(), A.end(), b) - A.begin();
        int diff1 = INF, diff2 = INF;
        if (c1 < N)
            diff1 = abs(b - A[c1]);
        if (0 < c1)
            diff2 = abs(b - A[c1 - 1]);
        cout << min(diff1, diff2) << endl;
    }
    return 0;
}