#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << min(A + B - C, D) << endl;
    return 0;
}