#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int x = 0;
    string S;
    cin >> S;
    vector<int> ans(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (S[i - 1] == 'I')
            x++;
        else if (S[i - 1] == 'D')
            x--;
        ans[i] = x;
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}