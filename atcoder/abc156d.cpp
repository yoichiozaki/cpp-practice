#include <bits/stdc++.h>
using namespace std;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint
{
    long long x; // typedef long long ll;
    mint(long long x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }
    mint pow(long long t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const
    {
        return pow(mod - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
};
// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&t=1619
struct combination
{
    vector<mint> fact, ifact;
    combination(int n) : fact(n + 1), ifact(n + 1)
    {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

mint choose(int n, int a)
{
    mint x = 1, y = 1;
    for (int i = 0; i < a; i++)
    {
        x *= n - i;
        y *= i + 1;
    }
    return x / y;
}

mint rpower(int x, int n)
{
    if (n == 0)
        return mint(1);
    mint ret = rpower(x, n / 2);
    ret *= ret;
    if (n % 2 == 1)
        ret *= x;
    return ret;
}

mint rpower2(int n)
{
    if (n == 0)
        return mint(1);
    mint ret = rpower2(n / 2);
    ret *= ret;
    if (n % 2 == 1)
        ret *= 2;
    return ret;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    mint ans = rpower(2, n);
    ans -= 1;
    ans -= choose(n, a);
    ans -= choose(n, b);
    cout << ans.x << endl;
    return 0;
}