#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int head = 0, tail = 0;
    int N = S.size();
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'a')
            head++;
        else
            break;
    }
    for (int i = N - 1; 0 < i; i--)
    {
        if (S[i] == 'a')
            tail++;
        else
            break;
    }
    if (head == N)
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (head > tail)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = head; i < (N - tail); i++)
    {
        if (S[i] != S[head + N - tail - i - 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}