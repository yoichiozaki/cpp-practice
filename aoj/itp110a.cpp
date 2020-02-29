#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << fixed << setprecision(12);
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) << endl;
    return 0;
}