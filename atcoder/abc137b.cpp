#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, X;
    cin >> K >> X;
    int left = max(-1000000, X - (K - 1) - 1);
    int right = min(1000000, X + (K - 1) - 1);
    for (int i = left + 1; i <= right + 1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}