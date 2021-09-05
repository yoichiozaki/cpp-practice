#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        P[i] -= 1;
    }
    vector<int> Q(N, 0);
    for (int i = 0; i < N; i++)
    {
        Q[P[i]] = i + 1;
    }
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
            cout << Q[i] << " ";
        else
            cout << Q[i] << endl;
    }
    return 0;
}