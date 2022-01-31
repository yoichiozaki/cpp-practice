#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    deque<int> Q = {N};
    for (int i = N - 1; 0 <= i; i--)
    {
        if (S[i] == 'L')
            Q.push_back(i);
        else
            Q.push_front(i);
    }
    for (int i = 0; i <= N; i++)
    {
        if (i < N)
            cout << Q[i] << " ";
        else
            cout << Q[i] << endl;
    }
    return 0;
}