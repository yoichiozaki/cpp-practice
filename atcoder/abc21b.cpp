#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, a, b;
    cin >> N >> a >> b;
    int K;
    cin >> K;
    set<int> s;
    for (int i = 0; i < K; i++)
    {
        int p;
        cin >> p;
        s.insert(p);
    }
    s.insert(a);
    s.insert(b);
    if (s.size() < K + 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}