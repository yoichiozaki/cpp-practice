#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (42 <= N)
        N++;
    cout << "AGC" << setfill('0') << setw(3) << N << endl;
    return 0;
}