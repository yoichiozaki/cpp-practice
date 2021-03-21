#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    for (long long i = 1;; i++)
    {
        if (N < stoll(to_string(i) + to_string(i)))
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
}