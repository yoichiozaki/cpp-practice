#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int c = N / 100;
    if (N % 100 != 0)
        c++;
    cout << c << endl;
    return 0;
}