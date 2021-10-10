#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> log; // <day, diff>
    int cnt = 0;
    vector<int> ans(N + 1, 0);

    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        log.push_back(make_pair(A, +1));
        log.push_back(make_pair(A + B, -1));
    }

    sort(log.begin(), log.end());

    for (int i = 0; i < log.size() - 1; i++)
    {
        cnt += log[i].second;
        ans[cnt] += log[i + 1].first - log[i].first;
    }

    for (int i = 1; i <= N - 1; i++)
        cout << ans[i] << " ";
    cout << ans[N] << endl;
    return 0;
}