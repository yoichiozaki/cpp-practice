#include <bits/stdc++.h>

using namespace std;

#define MAXP 1000005

vector<long long> primes;
void calc_primes() {
    vector<bool> is_prime(MAXP, false);
    for (int i = 2; i < MAXP; i++) {
        if (is_prime[i]) continue;
        primes.push_back(i);
        for (int j = i; j < MAXP; j += i) is_prime[j] = true;
    }
}

long long f(long long p,long long q){
    double est = 1;
    est = q * q * q;
    est *= p;
    if (est > 4e18) return 4e18;
    return p * q * q * q;
}

int main() {
    calc_primes();
    long long N; cin >> N;
    long long ans = 0;
    int size = primes.size();
    int q = size - 1;
    for (int p = 0; p < size; p++) {
        while (p < q && N < f(primes[p], primes[q])) q--;
        if (q <= p) break;
        ans += (q - p);
    }
    cout << ans << endl;
    return 0;
}