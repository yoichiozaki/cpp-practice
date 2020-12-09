#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        P[i] = pair<int, int>(x, y);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                int xi = P[i].first;
                int yi = P[i].second;
                int xj = P[j].first;
                int yj = P[j].second;
                int xk = P[k].first;
                int yk = P[k].second;
                xi -= xk;
                yi -= yk;
                xj -= xk;
                yj -= yk;
                if (xi * yj == xj * yi)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}