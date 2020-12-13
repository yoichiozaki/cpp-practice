#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, K, cnt = 0;
    cin >> A >> B >> C >> K;
    while (B <= A)
    {
        cnt++;
        B *= 2;
    }
    while (C <= B)
    {
        cnt++;
        C *= 2;
    }
    if (cnt <= K)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}