#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    if (m < 100)
        cout << setw(2) << setfill('0') << 0 << endl;
    else if (100 <= m && m <= 5000)
        cout << setw(2) << setfill('0') << m / 100 << endl;
    else if (6000 <= m && m <= 30000)
        cout << setw(2) << setfill('0') << m / 1000 + 50 << endl;
    else if (35000 <= m && m <= 70000)
        cout << setw(2) << setfill('0') << (m / 1000 - 30) / 5 + 80 << endl;
    else
        cout << setw(2) << setfill('0') << 89 << endl;
    return 0;
}