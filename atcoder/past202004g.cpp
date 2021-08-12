#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    deque<pair<char, int>> q;
    for (int _ = 0; _ < Q; _++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            char c;
            int x;
            cin >> c >> x;
            q.push_back(make_pair(c, x));
        }
        else
        {
            int d;
            cin >> d;
            map<char, int> deleted;

            while (0 < d)
            {
                if (q.size() == 0)
                    break;

                auto top = q.front();
                q.pop_front();
                int num_deleted = min(d, top.second);
                deleted[top.first] += num_deleted;
                top.second -= num_deleted;
                d -= num_deleted;

                if (0 < top.second)
                    q.push_front(top);
            }
            long long ans = 0;
            for (auto ele : deleted)
            {
                ans += 1LL * ele.second * ele.second;
            }
            cout << ans << endl;
        }
    }
    return 0;
}