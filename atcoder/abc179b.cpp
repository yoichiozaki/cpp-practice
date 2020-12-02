#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<bool> is_zorome(N);
    for (int i = 0; i < N; i++)
    {
        int d1, d2;
        cin >> d1 >> d2;
        if (d1 == d2)
            is_zorome[i] = true;
        else
            is_zorome[i] = false;
    }

    bool flag = false;

    for (int i = 0; i < N - 3 + 1; i++)
    {
        if (is_zorome[i] && is_zorome[i + 1] && is_zorome[i + 2])
            flag = true;
        if (flag)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}