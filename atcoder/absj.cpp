#include <bits/stdc++.h>

using namespace std;

int main()
{
    string parts[4] = {"dream", "dreamer", "erase", "eraser"};

    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; ++i)
        reverse(parts[i].begin(), parts[i].end());

    bool can = true;
    for (int i = 0; i < S.size();)
    {
        bool can2 = false;
        for (int j = 0; j < 4; ++j)
        {
            string d = parts[j];
            if (S.substr(i, d.size()) == d)
            {
                can2 = true;
                i += d.size();
            }
        }
        if (!can2)
        {
            can = false;
            break;
        }
    }

    if (can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}