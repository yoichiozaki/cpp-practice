#include <bits/stdc++.h>
using namespace std;

int main() {
    string A; cin >> A;
    string B; cin >> B;
    bitset<2000> A1(A);
    bitset<2000> B1(B);
    bitset<2000> ans = (A1 | B1); // A1とB1の和集合

    bool flag = false;
    for (int i = 1999; 0 <= i; i--) {
        if (ans[i] == 1) {
            flag = true;
        }
        if (flag == true) {
            cout << ans[i];
        }
    }
    return 0;
}