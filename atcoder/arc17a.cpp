#include <bits/stdc++.h>
using namespace std;

bool check(int N)
{
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    cout << (check(N) ? "YES" : "NO") << endl;
    return 0;
}