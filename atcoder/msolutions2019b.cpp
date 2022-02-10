#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int cnt = 0;
    for (char ch : S)
        if (ch == 'x')
            cnt++;
    if (cnt <= 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}