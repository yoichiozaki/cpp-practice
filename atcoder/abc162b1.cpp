#include <bits/stdc++.h>
using namespace std;

long long sum(long long n) {
    return n*(n-1)/2;
}

int main() {
    long long N; cin >> N;
    cout << sum(N) - sum(N/3)*3 - sum(N/5)*5 + sum(N/15)*15 << endl;
    return 0;
}