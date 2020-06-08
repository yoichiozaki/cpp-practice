#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> R(N), C(N);
    for (long long i = 0; i < N; i++)
        R[i] = C[i] = i;
    bool side = true; // N*R + C
    long long Q;
    cin >> Q;
    for (long long q = 0; q < Q; q++)
    {
        long long type;
        cin >> type;
        if (type == 1)
        {
            long long A, B;
            cin >> A >> B;
            A--, B--;
            swap(C[A], C[B]);
        }
        else if (type == 2)
        {
            long long A, B;
            cin >> A >> B;
            A--, B--;
            swap(R[A], R[B]);
        }
        else if (type == 3)
        {
            side = !side;
            swap(R, C);
        }
        else
        {
            long long A, B;
            cin >> A >> B;
            A--, B--;
            if (side)
                cout << N * R[A] + C[B] << endl;
            else
                cout << N * C[B] + R[A] << endl;
        }
    }
    return 0;
}