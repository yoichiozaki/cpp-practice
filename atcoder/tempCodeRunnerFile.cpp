#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (C == 0)
    {
        if (A % 2 == 0 && B % 2 == 0)
            cout << "Aoki" << endl;
        else if (A % 2 == 0 && B % 2 == 1)
            cout << "Takahashi" << endl;
        else if (A % 2 == 1 && B % 2 == 0)
            cout << "Takahashi" << endl;
        else
            cout << "Aoki" << endl;
    }
    else // C == 1
    {
        if (A % 2 == 0 && B % 2 == 0)
            cout << "Takahashi" << endl;
        else if (A % 2 == 0 && B % 2 == 1)
            cout << "Aoki" << endl;
        else if (A % 2 == 1 && B % 2 == 0)
            cout << "Aoki" << endl;
        else
            cout << "Takahashi" << endl;
    }
}