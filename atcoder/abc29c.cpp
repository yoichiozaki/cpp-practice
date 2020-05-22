#include <bits/stdc++.h>
using namespace std;

void DFS(int remain, string s)
{
    if (remain == 0)
    {
        cout << s << endl;
        return;
    }

    DFS(remain - 1, s + 'a');
    DFS(remain - 1, s + 'b');
    DFS(remain - 1, s + 'c');
}

int main()
{
    int N;
    cin >> N;
    DFS(N, "");
}
