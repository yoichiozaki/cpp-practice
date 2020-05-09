#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i] != i + 1)
            k++;
    }
    if (2 < k)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}