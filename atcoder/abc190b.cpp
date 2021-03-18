#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, S, D;
    cin >> N >> S >> D;
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        if (!(S <= X || Y <= D))
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}