#include <bits/stdc++.h>

using namespace std;

long long s[200005];

int main() {
    long long N, M, A, sum = 0;
    map<long long, long long> mp;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        mp[A] += 1;
        sum += A;
    }
    vector<pair<long long, long long>> vec;
    for (auto p: mp) vec.push_back(p);
    int k = vec.size();

    if (k == M) {
        cout << 0 << endl;
        return 0;
    }

    int p;
    for (int i = 0; i < k; i++) {
        if (vec[(i + 1) % k].first != (vec[i].first + 1) % M) {
            p = i;
            break;
        }
    }

    for (int i = 0; i < k; i++) {
        int j = (p - i + k) % k;
        s[j] = sum;
        if (vec[(j + 1) % k].first == (vec[j].first + 1) % M) {
            s[j] = s[(j + 1) % k];
        }
        s[j] -= vec[j].first * vec[j].second;
    }
    
    long long ans = sum;
    for (int i = 0; i < k; i++) {
        ans = min(ans, s[i]);
    }
    cout << ans << endl;
    return 0;
}