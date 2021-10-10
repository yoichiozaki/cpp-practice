#include <bits/stdc++.h>

using namespace std;

int game(char hand0, char hand1)
{
    if (hand0 == hand1)
        return -1;
    if (hand0 == 'G' && hand1 == 'P')
        return 1;
    if (hand0 == 'C' && hand1 == 'G')
        return 1;
    if (hand0 == 'P' && hand1 == 'C')
        return 1;
    return 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> hands(2 * N);
    for (int i = 0; i < 2 * N; i++)
        cin >> hands[i];

    vector<pair<int, int>> result;
    for (int i = 0; i < 2 * N; i++)
        result.push_back(make_pair(0, i));

    for (int round = 0; round < M; round++)
    {
        for (int i = 0; i < N; i++)
        {
            int player0 = result[2 * i].second;
            int player1 = result[2 * i + 1].second;
            char hand0 = hands[player0][round];
            char hand1 = hands[player1][round];
            int ret = game(hand0, hand1);
            if (ret == 0)
                result[2 * i].first -= 1;
            else if (ret == 1)
                result[2 * i + 1].first -= 1;
            else
                continue;
        }
        sort(result.begin(), result.end());
    }

    for (int i = 0; i < 2 * N; i++)
        cout << result[i].second + 1 << endl;
    return 0;
}