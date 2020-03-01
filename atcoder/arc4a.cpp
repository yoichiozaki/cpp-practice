#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(12);
    int n; cin >> n;
    double len = -1.0;
    vector<pair<double, double>> points(n, pair<double, double>(0.0, 0.0));
    for (int i = 0; i < n; i++) {
        cin >> points.at(i).first;
        cin >> points.at(i).second;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double tmp = sqrt((points.at(i).first - points.at(j).first)*(points.at(i).first - points.at(j).first) + (points.at(i).second - points.at(j).second)*(points.at(i).second - points.at(j).second));
            if (len < tmp) { len = tmp; }
        }
    }
    cout << len << endl;
    return 0;
}