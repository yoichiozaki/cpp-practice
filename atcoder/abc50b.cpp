#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];
    int M;
    cin >> M;
    vector<pair<int, int>> m;
    for (int i = 0; i < M; i++)
    {
        int p, x;
        cin >> p >> x;
        p--;
        m.push_back(make_pair(p, x));
    }
    for (int i = 0; i < M; i++)
    {
        int ans = 0;
        int oldp = m[i].first;
        int oldx = m[i].second;
        int tmp = T[oldp];
        T[oldp] = oldx;
        for (int i = 0; i < N; i++)
        {
            ans += T[i];
        }
        cout << ans << endl;
        T[oldp] = tmp;
    }
    return 0;
}