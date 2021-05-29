#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    unordered_set<string> table(S.begin(), S.end());
    for (auto s : S)
        if (table.count('!' + s))
        {
            cout << s << endl;
            return 0;
        }
    cout << "satisfiable" << endl;
    return 0;
}