#include <bits/stdc++.h>

using namespace std;

int main()
{
    int EAST = 0;
    int SOUTH = 1;
    int WEST = 2;
    int NORTH = 3;
    vector<pair<int, int>> diff(4);
    diff[EAST] = {+1, 0};
    diff[SOUTH] = {0, -1};
    diff[WEST] = {-1, 0};
    diff[NORTH] = {0, +1};

    int dir = EAST;
    pair<int, int> pos = {0, 0};
    int N;
    cin >> N;
    string T;
    cin >> T;
    for (int i = 0; i < N; i++)
    {
        char op = T[i];
        if (op == 'S')
        {
            pos.first += diff[dir].first;
            pos.second += diff[dir].second;
        }
        else
        { // op == 'R'
            dir += 1;
            dir %= 4;
        }
    }
    cout << pos.first << " " << pos.second << endl;
    return 0;
}