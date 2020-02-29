#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << fixed << setprecision(12);
    int n;
    cin >> n;
    vector<pair<double, double>> points(n, pair<int, int>(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> points.at(i).first;
    }
    for (int i = 0; i < n; i++) {
        cin >> points.at(i).second;
    }

    double dist = 0;
    for (int i = 0; i < n; i++) {
        dist += abs(points.at(i).first - points.at(i).second);
    }
    cout << dist << endl;;

    dist = 0;
    for (int i = 0; i < n; i++) {
        dist += pow(points.at(i).first - points.at(i).second, 2);
    }
    cout << pow(dist, (double)1/2) << endl;

    dist = 0;
    for (int i = 0; i < n; i++) {
        dist += pow(abs(points.at(i).first - points.at(i).second), 3);
    }
    cout << pow(dist, (double)1/3) << endl;

    dist = abs(points.at(0).first - points.at(0).second);
    for (int i = 0; i < n; i++) {
        if (dist < abs(points.at(i).first - points.at(i).second)) {
            dist = abs(points.at(i).first - points.at(i).second);
        }
    }
    cout << dist << endl;

    return 0;
}