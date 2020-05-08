#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long K;
    cin >> K;
    long long Q;
    cin >> Q;
    vector<long long> score(N, K - Q);
    for (long long i = 0; i < Q; i++)
    {
        int a;
        cin >> a;
        a--;
        score[a]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (score[i] <= 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}