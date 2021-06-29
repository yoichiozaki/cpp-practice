#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A < B)
    {
        if (B < C)
        {
            cout << "B" << endl;
        }
        else if (A < C)
        {
            cout << "C" << endl;
        }
        else
        {
            cout << "A" << endl;
        }
    }
    else
    {
        if (A < C)
        {
            cout << "A" << endl;
        }
        else if (B < C)
        {
            cout << "C" << endl;
        }
        else
        {
            cout << "B" << endl;
        }
    }
    return 0;
}