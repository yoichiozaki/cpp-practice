#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++)     // bottom-left
        for (int j = 0; j < n; j++) // top-right
            if (v[i].first < v[j].first && v[i].second < v[j].second)
            {
                if (binary_search(v.begin(), v.end(), make_pair(v[i].first, v[j].second)) && // top-left
                    binary_search(v.begin(), v.end(), make_pair(v[j].first, v[i].second)))   // bottom-right
                    ans++;
            }
    cout << ans << endl;
    return 0;
}