#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
    long long x;
    mint(long long x = 0) : x((x % mod + mod) % mod) {}
    mint operator - () const { return mint(-x); }
    mint &operator += (const mint a) {
        if (mod <= (x += a.x)) x -= mod;
        return *this;
    }
    mint &operator -= (const mint a) {
        if (mod <= (x += mod - a.x)) x -= mod;
        return *this;
    }
    mint &operator *= (const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator + (const mint a) const {
        return mint(*this) += a;
    }
    mint operator - (const mint a) const {
        return mint(*this) -= a;
    }
    mint operator * (const mint a) const {
        return mint(*this) *= a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }
    mint &operator /= (const mint a) {
        return *this = a.inv();
    }
    mint operator / (const mint a) const {
        return mint(*this) /= a;
    }
};
istream &operator >> (istream &is, const mint &a) {
    return is >> a.x;
}
ostream &operator << (ostream &os, const mint &a) {
    return os << a.x;
}

#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n = 1): n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; i++) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) {
        return f[x] == x;
    }
    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<int, int>> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

// gcd({a_1, a_2, ..., a_N})がiになるような数列a_nの個数をカウントすることができれば
// sigma(i*(gcd({a_1, a_2, ..., a_N})がiになるような数列a_nの個数))が答え

int main() {
    int n, k; cin >> n >> k;
    Sieve sieve(k);
    mint ans;
    vector<mint> d(k+1);
    for (int i = 1; i <= k; i++) {
        d[i] = mint(k/i).pow(n);
    }
    for (int p : sieve.primes) {
        for (int i = p; i <= k; i+= p) {
            d[i/p] -= d[i];
        }
    }
    for (int i = 1; i <= k; i++) {
        ans += d[i]*i;
    }
    cout << ans << endl;
    return 0;
}