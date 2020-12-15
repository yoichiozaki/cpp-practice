#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (i == N - 1)
            s = s.substr(0, s.size() - 1);
        if (s == "TAKAHASHIKUN" || s == "Takahashikun" || s == "takahashikun")
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}