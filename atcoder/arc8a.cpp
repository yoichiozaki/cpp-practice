#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << min(N / 10 * 100 + (N % 10) * 15, (N / 10 + 1) * 100) << endl;
    return 0;
}