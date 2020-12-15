#include <bits/stdc++.h>
using namespace std;

int main()
{
    char X;
    cin >> X;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == X)
            continue;
        cout << c;
    }
    cout << endl;
    return 0;
}