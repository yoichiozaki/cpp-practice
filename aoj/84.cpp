#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        if (!item.empty() && 3 <= item.size() && item.size() <= 6)
        {
            elems.push_back(item);
        }
    }
    return elems;
}

int main()
{
    string S;
    getline(cin, S);
    for (int i = 0; i < S.size(); i++)
        if (S[i] == ',' || S[i] == '.')
            S[i] = ' ';
    vector<string> ans = split(S, ' ');
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i] << endl;
        else
            cout << ans[i] << " ";
    }
    return 0;
}