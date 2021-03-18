#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (15 <= A + B && 8 <= B)
        cout << 1 << endl;
    else if (10 <= A + B && 3 <= B)
        cout << 2 << endl;
    else if (3 <= A + B)
        cout << 3 << endl;
    else
        cout << 4 << endl;
}