#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N, 0);
    vector<bool> ACed(N, false);
    int ac = 0, wa = 0;
    for (int i = 0; i < M; i++)
    {
        int p;
        string s;
        cin >> p >> s;
        if (ACed[p])
            continue;
        if (s == "AC")
        {
            ACed[p] = true;
            ac++;
            wa += a[p];
        }
        else if (s == "WA")
            a[p]++;
    }
    cout << ac << " " << wa << endl;
    return 0;
}