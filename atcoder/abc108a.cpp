#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    cin >> K;
    int even = 0, odd = 0;
    for (int i = 1; i <= K; i++)
    {
        if (i % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << even * odd << endl;
    return 0;
}