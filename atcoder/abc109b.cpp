#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (x[i].back() != x[i + 1].front())
        {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] == x[j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}