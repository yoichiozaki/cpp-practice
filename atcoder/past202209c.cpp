#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<double>> P(4, vector<double>(7, 0.0));
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 6; j++) {
            double p;
            cin >> p;
            P[i][j] = p / 100.0;
        }
    }
    vector<double> prob(20, 0.0);
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                prob[i + j + k] += P[1][i] * P[2][j] * P[3][k];
            }
        }
    }
    for (int i = 1; i <= 18; i++) cout << setprecision(12) << prob[i] << endl;
    return 0;
}