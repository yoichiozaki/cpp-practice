#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long now = 1;
    vector<long long> ans;
    while (N)
    {
        if (N % 3 == 1)
        {
            ans.push_back(now);
            N -= 1;
        }
        else if (N % 3 == 2)
        {
            ans.push_back(-now);
            N += 1;
        }
        now *= 3;
        N /= 3;
    }
    cout << ans.size() << endl;
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}