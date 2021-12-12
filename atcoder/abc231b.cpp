#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> votes(N);
    for (int i = 0; i < N; i++)
        cin >> votes[i];
    int max_vote = 0;
    string ans = "";
    for (int i = 0; i < N; i++)
    {
        string candidate = votes[i];
        int cnt = 0;
        for (int j = 0; j < N; j++)
            if (votes[j] == candidate)
                cnt++;
        if (max_vote < cnt)
        {
            max_vote = cnt;
            ans = candidate;
        }
    }
    cout << ans << endl;
    return 0;
}