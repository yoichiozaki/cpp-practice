#include <bits/stdc++.h>

using namespace std;

void dfs(int left, int right, int n, string sofar)
{
    if (left == n && right == n)
    {
        cout << sofar << endl;
        return;
    }
    if (left < n)
        dfs(left + 1, right, n, sofar + "(");
    if (right < left)
        dfs(left, right + 1, n, sofar + ")");
}

int main()
{
    int N;
    cin >> N;
    if (N % 2 == 1)
        return 0;
    dfs(0, 0, N / 2, "");
    return 0;
}