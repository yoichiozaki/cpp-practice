#include <bits/stdc++.h>

using namespace std;

#define MAXP 300005

vector<long long> sieve() {
    vector<long long> res;
    vector<int> mem(MAXP, 0);
    for (int i = 2; i < MAXP; i++) {
        if (mem[i]) continue;
        res.push_back(i);
        for (int j = i; j < MAXP; j += i) mem[j] = 1;
    }
    return res;
}

int main() {
    vector<long long> p = sieve();
    long long N; cin >> N;
    int sz = p.size();
    int res = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            for (int k =  j + 1; k < sz; k++) {
                long long v = p[i] * p[i] * p[j];
                if (v > N) break;
                v *= p[k];
                if (v > N) break;
                v *= p[k];
                if (v > N) break;
                res += 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}