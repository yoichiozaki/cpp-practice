#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<string, int>> playlist(N);
    for (int i = 0; i < N; i++)
    {
        cin >> playlist[i].first >> playlist[i].second;
    }
    string X;
    cin >> X;
    bool flag = false;
    int ans = 0;
    for (auto song : playlist)
    {
        if (flag == false && song.first == X)
        {
            flag = true;
            continue;
        }
        if (flag)
        {
            if (song.first == X)
            {
                break;
            }
            ans += song.second;
        }
    }
    cout << ans << endl;
    return 0;
}