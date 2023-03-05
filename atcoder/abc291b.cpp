#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    double s = 0;
    vector<double> A(5 * N);
    for (int i = 0; i < 5 * N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = N; i < 4 * N; i++) s += A[i];
    cout << s / (double)(3 * N) << endl;
    return 0;
}