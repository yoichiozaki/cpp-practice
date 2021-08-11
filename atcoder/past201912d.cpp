#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<int> cnt(200010, 0);
    for (int i = 0; i < N; i++)
    {
        cnt[A[i]] += 1;
    }

    int x = -1;
    int y = -1;
    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == 0)
            x = i;
        if (cnt[i] == 2)
            y = i;
    }

    if (x == -1)
        cout << "Correct" << endl;
    else
        cout << y << " " << x << endl;
    return 0;
}