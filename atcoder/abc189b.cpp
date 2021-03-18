#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int X;
    cin >> X;
    X *= 100;
    vector<pair<int, int>> sakes(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sakes[i].first >> sakes[i].second;
    }
    int has_drunk = 0;
    for (int i = 0; i < N; i++)
    {
        has_drunk += sakes[i].first * sakes[i].second;
        if (X < has_drunk)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}