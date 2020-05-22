#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N;
    cin >> N;
    vector<string> m;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < S.size(); j++)
        {
            string t = "";
            t.push_back(S[i]);
            t.push_back(S[j]);
            m.push_back(t);
        }
    }
    sort(m.begin(), m.end());
    cout << m[N - 1] << endl;
    return 0;
}