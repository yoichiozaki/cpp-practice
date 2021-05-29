#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, string>> table(N);
    for (int i = 0; i < N; i++)
    {
        string name;
        int height;
        cin >> name >> height;
        table[i] = make_pair(-height, name);
    }
    sort(table.begin(), table.end());
    cout << table[1].second << endl;
}