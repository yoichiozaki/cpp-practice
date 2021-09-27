#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long K;
    string A, B;
    cin >> K >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    long long a = 0, b = 0;
    long long base = 1;
    for (int i = 0; i < A.length(); i++)
    {
        long long digit = A[i] - '0';
        a += base * digit;
        base *= K;
    }
    base = 1;
    for (int i = 0; i < B.length(); i++)
    {
        long long digit = B[i] - '0';
        b += base * digit;
        base *= K;
    }
    cout << a * b << endl;
    return 0;
}