#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> candies(N, 0);
    for (int i = 0; i < N; i++)
        cin >> candies[i];

    map<int, int> counter;
    for (int i = 0; i < K; i++)
        counter[candies[i]] += 1;

    int ans = counter.size();

    for (int i = K; i < N; i++)
    {
        counter[candies[i]] += 1;
        counter[candies[i - K]] -= 1;
        if (counter[candies[i - K]] == 0)
            counter.erase(candies[i - K]);
        ans = max(ans, (int)counter.size());
    }

    cout << ans << endl;
    return 0;
}