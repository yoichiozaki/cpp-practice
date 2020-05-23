#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> m;
    int v = 0;
    string winner = "";
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        m[name]++;
        if (v < m[name])
            v = m[name], winner = name;
    }
    cout << winner << endl;
    return 0;
}