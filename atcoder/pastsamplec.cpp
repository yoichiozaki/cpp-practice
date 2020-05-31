#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> C;
    for (int i = 0; i < N; i++)
    {
        int c, t;
        cin >> c >> t;
        if (t <= T)
            C.push_back(c);
    }
    if (C.size() != 0)
    {
        sort(C.begin(), C.end());
        cout << C[0] << endl;
    }
    else
        cout << "TLE" << endl;
    return 0;
}