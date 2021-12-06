#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, A, B;
    cin >> N >> A >> B;
    long long P, Q, R, S;
    cin >> P >> Q >> R >> S;

    for (long long i = P; i <= Q; i++)
    {
        for (long long j = R; j <= S; j++)
        {
            if ((i - j) == (A - B))
                cout << "#";
            else if ((i + j) == (A + B))
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}