#include <bits/stdc++.h>

using namespace std;

// k番目に（小さい｜大きい）要素を高速に求める -> 長さkの優先度付きキューの利用
// kth smallest/largest element -> use priority queue with size k
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < K; i++)
        Q.push(P[i]);
    cout << Q.top() << endl;
    for (int i = K; i < N; i++)
    {
        if (Q.top() < P[i])
        {
            Q.pop();
            Q.push(P[i]);
        }
        cout << Q.top() << endl;
    }
    return 0;
}