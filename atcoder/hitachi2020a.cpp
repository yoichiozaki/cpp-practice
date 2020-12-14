#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    string hitachi = "";
    for (int i = 1; i <= 5; i++)
    {
        hitachi += "hi";
        if (hitachi == S)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}