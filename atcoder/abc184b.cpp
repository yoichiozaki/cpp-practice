#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    for (char c : S)
    {
        if (c == 'o')
            X++;
        else if (X != 0)
            X--;
    }
    cout << X << endl;
    return 0;
}