#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const long long MAX_N = 33;

struct Matrix
{
    long long sz;
    long long x[MAX_N][MAX_N];
};

Matrix multiply(Matrix A, Matrix B)
{
    Matrix C;
    C.sz = A.sz;
    for (int i = 0; i < C.sz; i++)
    {
        for (int j = 0; j < C.sz; j++)
        {
            C.x[i][j] = 0;
        }
    }
    for (int i = 0; i < A.sz; i++)
    {
        for (int j = 0; j < A.sz; j++)
        {
            for (int k = 0; k < A.sz; k++)
            {
                C.x[i][k] += (A.x[i][j] * B.x[j][k]) % MOD;
                C.x[i][k] %= MOD;
            }
        }
    }
    return C;
}

Matrix powers(Matrix A, long long T)
{
    Matrix E[64], F;
    E[0] = A;
    for (int i = 1; i < 62; i++)
    {
        E[i] = multiply(E[i - 1], E[i - 1]);
    }

    F.sz = E[0].sz;
    for (int i = 0; i < F.sz; i++)
    {
        for (int j = 0; j < F.sz; j++)
        {
            if (i == j)
                F.x[i][j] = 1;
            if (i != j)
                F.x[i][j] = 0;
        }
    }

    for (int i = 62; i >= 0; i--)
    {
        if ((T & (1LL << i)) != 0LL)
        {
            F = multiply(F, E[i]);
        }
    }
    return F;
}

int main()
{
    long long N, B, K;
    cin >> N >> B >> K;

    long long C[11];
    for (int i = 1; i <= K; i++)
        cin >> C[i];

    Matrix A;
    A.sz = B;
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < B; j++)
        {
            A.x[i][j] = 0;
        }
    }

    for (int i = 0; i < B; i++)
    {
        for (auto c : C)
        {
            A.x[i][(i * 10 + c) % 10] += 1;
        }
    }

    Matrix Z = powers(A, N);
    cout << Z.x[0][0] << endl;
    return 0;
}