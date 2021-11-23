#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    K -= 1;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        P[i] = p1 + p2 + p3;
    }
    vector<int> Q = P;
    sort(Q.begin(), Q.end(), greater<int>());
    for (int i = 0; i < N; i++)
    {
        if (Q[K] <= P[i] + 300)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}