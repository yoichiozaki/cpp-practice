#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    for (int i = 1; i <= N; i++)
    {
        int item;
        cin >> item;
        if (i % 2 == 0)
            item -= 1;
        X -= item;
    }
    if (0 <= X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}