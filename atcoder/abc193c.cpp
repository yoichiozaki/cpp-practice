#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    unordered_set<long long> s;
    for (long long a = 2; a * a <= N; a++)
    {
        long long x = a * a;
        while (x <= N)
        {
            s.insert(x);
            x *= a;
        }
    }

    cout << N - s.size() << endl;
    return 0;
}