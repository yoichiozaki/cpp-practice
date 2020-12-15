#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> E(6);
    int B;
    vector<int> L(6);
    for (int i = 0; i < 6; i++)
        cin >> E[i];
    cin >> B;
    for (int i = 0; i < 6; i++)
        cin >> L[i];
    bool flag = false;
    int match = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (E[i] == L[j])
            {
                L[j] = -1;
                match++;
            }
            else if (L[j] == B)
                flag = true;
        }
    }
    int ans = 0;
    if (match == 6)
        ans = 1;
    else if (match == 5)
    {
        if (flag)
            ans = 2;
        else
            ans = 3;
    }
    else if (match == 4)
        ans = 4;
    else if (match == 3)
        ans = 5;
    cout << ans << endl;
    return 0;
}