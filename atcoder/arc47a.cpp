#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    string S;
    cin >> S;
    int tab = 1;
    int crash = 0;
    for (auto c : S)
    {
        if (c == '+')
            tab++;
        else
            tab--;
        if (L < tab)
        {
            crash++;
            tab = 1;
        }
    }
    cout << crash << endl;
    return 0;
}