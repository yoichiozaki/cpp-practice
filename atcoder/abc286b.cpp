#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    string ans = "";
    for (int i = 0; i < N; i++) {
        if (1 <= i && ans[ans.size() - 1] == 'n' && S[i] == 'a') {
            ans.push_back('y');
        } 
        ans.push_back(S[i]);
    }
    cout << ans << endl;
    return 0;
}