#include <bits/stdc++.h>

using namespace std;

vector<int> prime_factorization(int x)
{
    vector<int> ret;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            ret.push_back(i);
        }
    }
    if (x != 1)
        ret.push_back(x);
    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<bool> is_candidate(100005, true);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vector<int> primes = prime_factorization(a);
        for (auto prime : primes)
        {
            if (is_candidate[prime])
            {
                for (int j = prime; j < 100005; j += prime)
                {
                    is_candidate[j] = false;
                }
            }
        }
    }

    vector<int> ret;
    for (int i = 1; i <= M; i++)
    {
        if (is_candidate[i])
            ret.push_back(i);
    }

    cout << ret.size() << endl;
    for (auto ele : ret)
        cout << ele << endl;
    return 0;
}