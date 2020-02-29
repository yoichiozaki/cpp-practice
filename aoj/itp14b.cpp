#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(12);

    double r;
    cin >> r;

    double area = r * r * M_PI;
    double cir = (r + r) * M_PI;
    cout << area << " " << cir << endl;
    return 0;
}