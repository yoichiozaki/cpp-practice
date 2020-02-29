#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << fixed << setprecision(12);
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<double> vec(n, 0);
        double average = 0;
        for (int i = 0; i < n; i++) {
            cin >> vec.at(i);
            average += vec.at(i);
        }
        average /= n;
        double stddev = 0;
        for (int i = 0; i < n; i++) {
            stddev += (vec.at(i) - average)*(vec.at(i) - average);
        }
        stddev /= n;
        cout << sqrt(stddev) << endl;
    }
    return 0;
}