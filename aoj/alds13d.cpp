#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> S1;
    stack<pair<int, int>> S2;
    char ch;
    int sum = 0;
    for (int i = 0; cin >> ch; i++) {
        if (ch == '\\') S1.push(i);
         else if (ch == '/' && 0 < S1.size()) {
             int j = S1.top(); S1.pop();
             sum += i - j;
             int a = i - j;
             while (0 < S2.size() && j < S2.top().first) {
                 a += S2.top().second; S2.top();
             }
             S2.push(make_pair(j, a));
         }
    }

    vector<int> ans;
    while (0 < S2.size()) {
        ans.push_back(S2.top().second); S2.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << sum << endl;
    cout << ans.size();
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}