#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A < C)
        cout << "Takahashi" << endl;
    else if (A == C)
    {
        if (B < D)
            cout << "Takahashi" << endl;
        else if (B >= D)
            cout << "Aoki" << endl;
    }
    else
        cout << "Aoki" << endl;
    return 0;
}