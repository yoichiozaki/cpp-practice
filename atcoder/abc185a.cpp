#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;
    cout << min(A1, min(A2, min(A3, A4))) << endl;
    return 0;
}