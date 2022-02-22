#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    vector<pair<int, int>> balls;
    for (int i = 0; i < N; i++)
    {
        int ball;
        cin >> ball;
        cnt++;
        if (balls.empty() || balls.back().first != ball)
            balls.push_back(make_pair(ball, 1));
        else
        {
            balls.back().second += 1;
            if (balls.back().second == ball)
            {
                cnt -= ball;
                balls.pop_back();
            }
        }
        cout << cnt << endl;
    }
    return 0;
}