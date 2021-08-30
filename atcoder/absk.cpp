#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> t(N + 1, 0);
    vector<int> x(N + 1, 0);
    vector<int> y(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> t[i] >> x[i] >> y[i];

    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        int dt = t[i + 1] - t[i];
        int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        if (dt < dist)
            flag = false;
        if (dist % 2 != dt % 2)
            flag = false;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}