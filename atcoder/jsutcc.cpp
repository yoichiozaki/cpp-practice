#include <bits/stdc++.h>
using namespace std;

int a, b, c, ans;
void DFS(int A, int B, int C)
{
    if (a < A)
        return;
    if (b < B)
        return;
    if (c < C)
        return;
    if (A == a && B == b && C == c)
    {
        ans++;
        return;
    }
    DFS(A + 1, B, C);
    if (B < A)
        DFS(A, B + 1, C);
    if (C < B)
        DFS(A, B, C + 1);
}

int main()
{
    cin >> a >> b >> c;
    DFS(1, 0, 0);
    cout << ans << endl;
}