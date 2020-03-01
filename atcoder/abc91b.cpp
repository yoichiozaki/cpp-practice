#include <bits/stdc++.h>
using namespace std;

struct second_order {
    bool operator()(const pair<string, int>& x, const pair<string, int>& y) const {
        return x.second < y.second;
    }
};

int main() {
    map<string, int> table;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        table[s]++;
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        table[s]--;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, second_order> que;
    for (auto p : table) {
        que.push(p);
    }
    if (que.top().second < 0) {
        cout << 0 << endl;
    } else {
        cout << que.top().second << endl;
    }
    return 0;
}