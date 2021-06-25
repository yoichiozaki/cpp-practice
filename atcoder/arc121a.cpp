#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> houses;
    set<int> house_ids;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        houses.emplace_back(vector<int>{x, y, i});
    }
    for (int k = 0; k < 2; k++)
    {
        sort(houses.begin(), houses.end());
        for (int i = 0; i < 2; i++)
        {
            house_ids.emplace(houses[i][2]);
            house_ids.emplace(houses[N - 1 - i][2]);
        }
        for (auto &house : houses)
        {
            swap(house[0], house[1]);
        }
    }
    vector<pair<int, int>> candidate_houses;
    for (auto house : houses)
    {
        if (house_ids.count(house[2]) != 0)
        {
            candidate_houses.emplace_back(house[0], house[1]);
        }
    }
    vector<long long> dist;
    for (int i = 0; i < candidate_houses.size(); i++)
    {
        for (int j = i + 1; j < candidate_houses.size(); j++)
        {
            dist.emplace_back(
                max(
                    abs(candidate_houses[i].first - candidate_houses[j].first),
                    abs(candidate_houses[i].second - candidate_houses[j].second)));
        }
    }
    sort(dist.begin(), dist.end());
    cout << dist[dist.size() - 2] << endl;
    return 0;
}