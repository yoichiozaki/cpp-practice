#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (0 < A && B == 0)
    {
        cout << "Gold" << endl;
        return 0;
    }
    if (A == 0 && 0 < B)
    {
        cout << "Silver" << endl;
        return 0;
    }
    if (0 < A && 0 < B)
    {
        cout << "Alloy" << endl;
        return 0;
    }
    return 0;
}