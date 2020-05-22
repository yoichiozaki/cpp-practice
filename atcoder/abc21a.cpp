#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 1)
        cout << 1 << endl
             << 1 << endl;
    else if (N == 2)
        cout << 1 << endl
             << 2 << endl;
    else if (N == 3)
        cout << 2 << endl
             << 1 << endl
             << 2 << endl;
    else if (N == 4)
        cout << 1 << endl
             << 4 << endl;
    else if (N == 5)
        cout << 2 << endl
             << 1 << endl
             << 4 << endl;
    else if (N == 6)
        cout << 2 << endl
             << 2 << endl
             << 4 << endl;
    else if (N == 7)
        cout << 3 << endl
             << 1 << endl
             << endl
             << 2 << endl
             << 4;
    else if (N == 8)
        cout << 1 << endl
             << 8 << endl;
    else if (N == 9)
        cout << 2 << endl
             << 1 << endl
             << 8 << endl;
    else if (N == 10)
        cout << 2 << endl
             << 2 << endl
             << 8 << endl;

    return 0;
}