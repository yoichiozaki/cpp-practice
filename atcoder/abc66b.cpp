#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    for (int i = S.size() - 2; i; i -= 2)
    {
        if (S.compare(0, i / 2, S, i / 2, i / 2) == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}