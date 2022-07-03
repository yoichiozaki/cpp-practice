#include <bits/stdc++.h>

using namespace std;

string format(int x) {
    if (x < 10) return string{'0'} + to_string(x);
    else return to_string(x);
}

int main() {
    int K; cin >> K;
    int H = K < 60 ? 21 : 22;
    int M = K % 60;
    cout << H << ":" << format(M) << endl;
    return 0;
}