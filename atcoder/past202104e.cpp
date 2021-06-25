#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    deque<int> q;
    for (int i = 0; i < N; i++)
    {
        switch (S[i])
        {
        case 'L':
            q.push_front(i + 1);
            break;
        case 'R':
            q.push_back(i + 1);
            break;
        case 'A':
        case 'B':
        case 'C':
        {
            int x = S[i] - 'A';
            if (q.size() <= x)
                cout << "ERROR" << endl;
            else
            {
                cout << q[x] << endl;
                q.erase(q.begin() + x);
            }
            break;
        }
        case 'D':
        case 'E':
        case 'F':
        {
            int x = S[i] - 'D';
            if (q.size() <= x)
                cout << "ERROR" << endl;
            else
            {
                cout << q.end()[~x] << endl;
                q.erase(q.end() - 1 - x);
            }
            break;
        }
        }
    }
    return 0;
}