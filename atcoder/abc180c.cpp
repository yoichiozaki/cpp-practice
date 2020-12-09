#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    set<long long> ans;
    for (long long i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ans.insert(i);
            ans.insert(N / i);
        }
    }

    for (long long s : ans)
        cout << s << endl;
    return 0;
}