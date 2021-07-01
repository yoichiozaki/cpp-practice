#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    vector<int> votes(3, 0);
    for (int i = 0; i < S.size(); i++)
    {
        votes[S[i] - 'a']++;
    }
    cout << char(max_element(votes.begin(), votes.end()) - votes.begin() + 'a') << endl;
    return 0;
}