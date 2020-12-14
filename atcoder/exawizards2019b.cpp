#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (N % 2 == 0)
    {
        if (s[N / 2 - 1] == 'R')
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        if (s[N / 2] == 'B')
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}