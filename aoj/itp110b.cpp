#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << fixed << setprecision(12);
    double a, b, c, C, S, l;
    cin >> a >> b >> C;
    S = a * b * sin(M_PI*C/180) / 2;
    c = sqrt(a*a + b*b - 2*a*b*cos(M_PI*C/180));
    l = b * sin(M_PI*C/180);
    cout << S << " "
         << a + b + c << " "
         << l << endl;
    return 0;
}