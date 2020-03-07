#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, A, B; cin >> N >> A >> B;
    if (N%(A+B) <= A) {
        cout << N/(A+B) * A + N%(A+B) << endl;
    } else {
        cout << N/(A+B) * A + A << endl;
    }
    return 0;
}