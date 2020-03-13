#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
struct mint {
    long long x;
    mint(long long x = 0) : x ((x%mod + mod)%mod) { }
    mint operator- () const { return mint(-x); }
    mint& operator+= (const mint a) {
        if (mod <= (x += a.x)) {
            x -= mod;
        }
        return *this;
    }
    mint& operator-= (const mint a) {
        if (mod <= (x += mod - a.x)) {
            x -= mod;
        }
        return *this;
    }
    mint& operator*= (const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+ (const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator- (const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator* (const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(long long t) const {
        if (!t) {
            return 1;
        }
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) {
            a *= *this;
        }
        return a;
    }
    mint inv() const {
        return pow(mod - 2);
    }
    mint& operator/= (const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/ (const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

vector<int> to[200005];

mint dfs(int v) {
    mint res = 1;
    for (int u : to[v]) {
        res *= dfs(u);
    }
    return res + 1;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    set<pair<int, int>> s;
    for (int i = n-1; 0 <= i; i--) {
        int x = p[i].first, d = p[i].second;
        while (s.size() && s.begin()->first < x+d) {
            to[i].push_back(s.begin()->second);
            s.erase(s.begin());
        }
        s.emplace(x, i);
    }

    mint ans = 1;
    for (auto x : s) {
        int v = x.second;
        ans *= dfs(v);
    }
    cout << ans.x << endl;
    return 0;
}