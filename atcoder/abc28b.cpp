#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    map<char, int> m;
    for (auto c : S)
    {
        m[c]++;
    }
    for (int i = 0; i < 6; i++)
    {
        if (i == 5)
        {
            cout << m['F'] << endl;
        }
        else
        {
            cout << m[char('A' + i)] << " ";
        }
    }
    return 0;
}
