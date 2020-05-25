#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    vector<string> subs(K);
    for (int i = 0; i < T.size(); i++)
        subs[i % K].push_back(T[i]);

    map<pair<char, char>, int> handmap;
    handmap[make_pair(0, 'r')] = 0;
    handmap[make_pair(0, 's')] = R;
    handmap[make_pair(0, 'p')] = 0;
    handmap[make_pair(1, 'r')] = 0;
    handmap[make_pair(1, 's')] = 0;
    handmap[make_pair(1, 'p')] = S;
    handmap[make_pair(2, 'r')] = P;
    handmap[make_pair(2, 's')] = 0;
    handmap[make_pair(2, 'p')] = 0;

    int dp[100010][3] = {};

    int score = 0;
    for (auto s : subs)
    {
        // 初期化
        for (int i = 0; i < 100010; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = 0;

        dp[0][0] = handmap[make_pair(0, s[0])];
        dp[0][1] = handmap[make_pair(1, s[0])];
        dp[0][2] = handmap[make_pair(2, s[0])];

        for (int j = 1; j < s.size(); j++)
        {
            dp[j][0] = max(dp[j - 1][1], dp[j - 1][2] + handmap[make_pair(0, s[j])]);
            dp[j][1] = max(dp[j - 1][2], dp[j - 1][0] + handmap[make_pair(1, s[j])]);
            dp[j][2] = max(dp[j - 1][0], dp[j - 1][1] + handmap[make_pair(2, s[j])]);
        }
        score += max(dp[s.size() - 1][0], max(dp[s.size() - 1][1], dp[s.size() - 1][2]));
    }
    cout << score << endl;
    return 0;
}