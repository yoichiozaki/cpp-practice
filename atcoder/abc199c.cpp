#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    string head = S.substr(0, N);
    string tail = S.substr(N);

    for (int _ = 0; _ < Q; _++)
    {
        int T, A, B;
        cin >> T >> A >> B;
        if (T == 1)
        {
            A--;
            B--;
            if (B < N)
                swap(head[A], head[B]);
            else if (N <= A)
                swap(tail[A - N], tail[B - N]);
            else
                swap(head[A], tail[B - N]);
        }
        else
        {
            swap(head, tail);
        }
    }
    cout << head << tail << endl;
    return 0;
}