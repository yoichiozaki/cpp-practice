#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A * D < B * C)
        cout << "TAKAHASHI" << endl;
    else if (A * D == B * C)
        cout << "DRAW" << endl;
    else
        cout << "AOKI" << endl;
    return 0;
}