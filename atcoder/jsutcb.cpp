#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'B')
            c = 'b';
        pq.push(make_pair(c, x));
    }
    while (!pq.empty())
    {
        cout << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}