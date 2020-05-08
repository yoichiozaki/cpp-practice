#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> frq;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        frq[s]++;
    }
    int maxf = 0;
    for (auto x : frq)
    {
        int f = x.second;
        if (maxf < f)
            maxf = f;
    }
    for (auto iter = frq.begin(); iter != frq.end(); iter++)
    {
        if (iter->second == maxf)
        {
            cout << iter->first << endl;
        }
    }
    return 0;
}