#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A + B > C + D)
        cout << "Left" << endl;
    else if (A + B == C + D)
        cout << "Balanced" << endl;
    else
        cout << "Right" << endl;
    return 0;
}