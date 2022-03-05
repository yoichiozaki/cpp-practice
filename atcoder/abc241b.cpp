#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    map<int, int> table;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        table[A]++;
    }
    for (int i = 0; i < M; i++)
    {
        int B;
        cin >> B;
        if (table[B] == 0)
        {
            cout << "No" << endl;
            return 0;
        }
        table[B]--;
    }
    cout << "Yes" << endl;
    return 0;
}