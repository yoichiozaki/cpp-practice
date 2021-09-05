#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> check{false, false, false, false};
    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        if (s == "ABC")
            check[0] = true;
        else if (s == "AGC")
            check[1] = true;
        else if (s == "AHC")
            check[2] = true;
        else
            check[3] = true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!check[i])
        {
            if (i == 0)
                cout << "ABC" << endl;
            else if (i == 1)
                cout << "AGC" << endl;
            else if (i == 2)
                cout << "AHC" << endl;
            else
                cout << "ARC" << endl;
        }
    }
    return 0;
}