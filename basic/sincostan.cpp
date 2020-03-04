#include <bits/stdc++.h>
using namespace std;

int main() {
    double x; cin >> x;
    cout << "sin(" << x/180.0 << "PI) = " << sin(x*M_PI/180.0) << endl;
    cout << "cos(" << x/180.0 << "PI) = " << cos(x*M_PI/180.0) << endl;
    cout << "tan(" << x/180.0 << "PI) = " << tan(x*M_PI/180.0) << endl;
}