#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    set<string> s;
    for (int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;
        if (s.insert(name).second)
        {
            cout << i << endl;
        }
    }
    return 0;
}