#include <bits/stdc++.h>
using namespace std;

long long SumOfDigits(long long n) {
    long long sum = 0LL;
    while (n) {
        sum += n%10LL;
        n /= 10LL;
    }
    return sum;
}

int main() {
    long long N, minimum = 1e7;
    cin >> N;
    for (long long a = 1; a < N; a++) {
        long long b = N - a;
        long long ab = SumOfDigits(a) + SumOfDigits(b);
        if (ab < minimum) { minimum = ab; }
    }
    cout << minimum << endl;
}