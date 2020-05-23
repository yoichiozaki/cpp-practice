#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int h = N / (60 * 60);
    N %= 60 * 60;
    int m = N / 60;
    int s = N % 60;
    cout << setw(2) << setfill('0')
         << h << ":"
         << setw(2) << setfill('0')
         << m << ":"
         << setw(2) << setfill('0')
         << s << endl;
    return 0;
}