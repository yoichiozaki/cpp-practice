#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << max({103, 168, 103}) << endl;

    int N, c[100009], minx = 2147483647;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= N; i++) {
        minx = min(minx, c[i]);
    }
    cout << minx << endl;

    // {c[1], c[2], ..., c[N]} の最小値を出力
    cout << *min_element(c+1, c+N+1) << endl;
}