#include <bits/stdc++.h>

using namespace std;

int main() {
    long long Q; cin >> Q;
    deque<pair<long long, long long>> cylinder;
    for (long long i = 0; i < Q; i++) {
        long long q; cin >> q;
        switch (q)
        {
        case 1:
            long long x, c; cin >> x >> c;
            cylinder.push_back(make_pair(x, c));
            break;
        case 2:
            cin >> c;
            long long cnt = 0;
            long long ret = 0;
            while (cnt < c) {
                pair<long long, long long> balls = cylinder.front();
                cylinder.pop_front();
                long long remain = balls.second - min(balls.second, c - cnt);
                ret += balls.first * min(balls.second, c - cnt);
                cnt += balls.second;
                if (0 < remain) {
                    cylinder.push_front(make_pair(balls.first, remain));
                }
            }
            cout << ret << endl;
            break;
        }
    }
    return 0;
}