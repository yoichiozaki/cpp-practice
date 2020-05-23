#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int remain = 2025 - N;
    vector<pair<int, int>> m;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i * j == remain)
                m.push_back(make_pair(i, j));
        }
    }
    for (auto item : m)
    {
        cout << item.first << " x " << item.second << endl;
    }
    return 0;
}