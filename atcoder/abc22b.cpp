#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (s.count(a) != 0)
            ans++;
        s.insert(a);
    }
    cout << ans << endl;
}
