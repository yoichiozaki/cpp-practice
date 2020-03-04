#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> d(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end());
    int answer = d.at(d.size()/2) - d.at(d.size()/2-1);
    cout << answer << endl;
    return 0;
}