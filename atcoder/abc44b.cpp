#include <bits/stdc++.h>
using namespace std;

int main()
{
    string w;
    cin >> w;
    map<char, int> m;
    for (int i = 0; i < w.size(); i++)
        m[w[i]]++;
    bool beautiful = true;
    for (auto item : m)
    {
        if (item.second % 2 == 1)
        {
            beautiful = false;
            break;
        }
    }
    if (beautiful)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}