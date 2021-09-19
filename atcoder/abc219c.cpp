#include <bits/stdc++.h>

using namespace std;

int main()
{
    string X;
    cin >> X;
    vector<int> alphabets(26, 0);
    for (int i = 0; i < 26; i++)
        alphabets[X[i] - 'a'] = i;

    int N;
    cin >> N;
    vector<string> names(N);
    for (int i = 0; i < N; i++)
        cin >> names[i];

    sort(names.begin(), names.end(), [&](const string &lhs, const string &rhs)
         {
             int len = min(lhs.size(), rhs.size());
             for (int i = 0; i < len; i++)
             {
                 if (lhs[i] != rhs[i])
                     return alphabets[lhs[i] - 'a'] < alphabets[rhs[i] - 'a'];
             }
             return lhs.size() < rhs.size();
         });

    for (auto name : names)
        cout << name << endl;
    return 0;
}