#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> seen(2020, false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        seen[A] = true;
    }
    for (int i = 0; i <= N; i++)
    {
        if (!seen[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}