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
    long long N;
    cin >> N;
    cout << (N%SumOfDigits(N) == 0 ? "Yes" : "No") << endl;
}