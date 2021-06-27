#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(A + B, max(B + C, C + A)) << endl;
    return 0;
}