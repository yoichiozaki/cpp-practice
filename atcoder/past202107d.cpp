#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> targets = {"axa", "ixi", "uxu", "exe", "oxo"};
    long long N;
    string S;
    cin >> N >> S;
    for (int pos = 0; pos <= N - 3; pos++)
    {
        bool flag = false;
        string sub = S.substr(pos, 3);
        for (auto target : targets)
        {
            if (sub == target)
            {
                flag = true;
            }
        }
        if (flag)
        {
            S[pos + 0] = '.';
            S[pos + 1] = '.';
            S[pos + 2] = '.';
        }
    }
    cout << S << endl;
    return 0;
}