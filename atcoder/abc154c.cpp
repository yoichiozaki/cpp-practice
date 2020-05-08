#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<long long> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        s.insert(a);
    }
    if (N == s.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}