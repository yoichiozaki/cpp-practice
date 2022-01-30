#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    map<int, int> cnt;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        cnt[A] += 1;
    }
    cout << cnt[X] << endl;
    return 0;
}