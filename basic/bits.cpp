#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    bool ans = false;

    for (int tmp = 0; tmp < (1 << N); tmp++) {
        bitset<N> s(tmp);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (s.test(i)) {
                sum += A.at(i);
            }
        }
        if (sum == K) {
            ans = true;
        }
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // bitset -> 整数: bitsetの変数.to_ullong()
    // 0b001101011 // 2進数リテラル
}
