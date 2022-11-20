#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    char c = 'a' - 1 + ((S.size() - 1) / 3);
    int pre;
    if (S.size() % 3 == 0) pre = 3;
    else pre = S.size() % 3;
    for (int i = 0; i < pre; i++) cout << S[i];
    cout << c << endl;
    return 0;
}