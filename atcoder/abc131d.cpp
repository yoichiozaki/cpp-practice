#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> tasks(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        tasks[i] = make_pair(b, a);
    }
    sort(tasks.begin(), tasks.end()); // 締切の近い順にソート
    int t = 0;
    bool can = true;
    for (auto task : tasks)
    {
        t += task.second;
        if (task.first < t)
        { // 締め切りを過ぎたか
            can = false;
            break;
        }
    }
    cout << (can ? "Yes" : "No") << endl;
    return 0;
}