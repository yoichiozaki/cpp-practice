#include <bits/stdc++.h>
using namespace std;

int main()
{
    string W;
    cin >> W;
    for (int i = 0; i < W.size(); i++)
    {
        if (W[i] == 'a' || W[i] == 'i' || W[i] == 'u' || W[i] == 'e' || W[i] == 'o')
            continue;
        cout << W[i];
    }
    cout << endl;
    return 0;
}