#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> p(5);
    for (int i = 0; i < 5; i++)
        cin >> p[i];
    sort(p.begin(), p.end(), greater<int>());
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            cout << p[i] << endl;
        }
        else
        {
            cout << p[i] << " ";
        }
    }
    return 0;
}