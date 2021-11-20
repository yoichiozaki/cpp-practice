#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> C(N, 0);
    vector<int> P(N, 0);
    for (int i = 0; i < N; i++)
        cin >> C[i] >> P[i];
    vector<int> accum1(N + 1, 0);
    vector<int> accum2(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        if (C[i] == 1)
        {
            accum1[i + 1] = accum1[i] + P[i];
            accum2[i + 1] = accum2[i];
        }
        else
        {
            accum1[i + 1] = accum1[i];
            accum2[i + 1] = accum2[i] + P[i];
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int L, R;
        cin >> L >> R;
        L--, R--;
        cout << accum1[R + 1] - accum1[L] << " " << accum2[R + 1] - accum2[L] << endl;
    }
    return 0;
}