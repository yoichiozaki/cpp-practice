#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> x(3, 0);
    cin >> x[0] >> x[1] >> x[2];
    sort(x.begin(), x.end());
    if (x[0] == 5 && x[1] == 5 && x[2] == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}