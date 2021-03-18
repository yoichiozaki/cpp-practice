#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first >> A[i].second;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int x0 = A[i].first;
            int y0 = A[i].second;
            int x1 = A[j].first;
            int y1 = A[j].second;
            if (abs(y0 - y1) <= abs(x0 - x1))
            {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}