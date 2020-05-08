#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> x(2);
    cin >> x[0] >> x[1];
    sort(x.begin(), x.end());
    if (x[0] == 1 && x[1] == 2)
        cout << 3 << endl;
    else if (x[0] == 1 && x[1] == 3)
        cout << 2 << endl;
    else if (x[0] == 2 && x[1] == 3)
        cout << 1 << endl;
    return 0;
}