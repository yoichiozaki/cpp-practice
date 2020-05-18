#include <bits/stdc++.h>
using namespace std;

int main()
{
    string O, E;
    cin >> O >> E;
    vector<char> ans(O.size() + E.size());
    for (int i = 0; i < O.size(); i++)
        ans[2 * i] = O[i];
    for (int i = 0; i < E.size(); i++)
        ans[2 * i + 1] = E[i];
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;
    return 0;
}