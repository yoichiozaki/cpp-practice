#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int N;
    cin >> N;
    queue<int> tako;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        tako.push(t);
    }
    int M;
    cin >> M;
    queue<int> customer;
    for (int i = 0; i < M; i++)
    {
        int t;
        cin >> t;
        customer.push(t);
    }

    if (N < M)
    {
        cout << "no" << endl;
        return 0;
    }

    while (!tako.empty())
    {
        int next_tako = tako.front();
        int next_customer = customer.front();
        if (next_tako <= next_customer)
        {
            tako.pop();
            if (next_customer - next_tako <= T)
                customer.pop();
        }
        else
        {
            tako.pop();
        }
    }

    if (customer.empty())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}