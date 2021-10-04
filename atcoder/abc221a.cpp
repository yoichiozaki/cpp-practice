#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    printf("%d\n", 1 << (5 * (A - B)));
    return 0;
}