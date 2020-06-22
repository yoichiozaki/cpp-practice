#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int s = 0;
    for (int i = 0; i < N; i++)
        s ^= a[i];
    for (int i = 0; i < N; i++)
        a[i] ^= s;
    for (int i = 0; i < N; i++)
        cout << a[i] << endl;
    return 0;
}