#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> y(3);
    for (int i = 0; i < 3; i++)
        cin >> y[i];
    sort(y.begin(), y.end());
    cout << y[1] << endl;
    return 0;
}