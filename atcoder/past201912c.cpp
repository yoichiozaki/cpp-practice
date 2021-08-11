#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> X(6, 0);
    cin >> X[0] >> X[1] >> X[2] >> X[3] >> X[4] >> X[5];
    sort(X.begin(), X.end(), greater<int>());
    cout << X[2] << endl;
    return 0;
}