#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.length();

    vector<pair<string, string>> elements;

    string buf = "";
    int capital_counter = 0;

    for (int i = 0; i < N; i++)
    {
        buf += S[i];
        if ('A' <= S[i] && S[i] <= 'Z')
        {
            capital_counter += 1;
            if (capital_counter % 2 == 0)
            {
                string s = buf;
                transform(s.begin(), s.end(), s.begin(), ::tolower);
                elements.push_back(make_pair(s, buf));
                buf = "";
            }
        }
    }

    sort(elements.begin(), elements.end());
    string ans = "";
    for (auto e : elements)
        ans += e.second;
    cout << ans << endl;

    return 0;
}