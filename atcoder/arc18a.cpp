#include <bits/stdc++.h>
using namespace std;

int main()
{
    double H, BMI;
    cin >> H >> BMI;
    cout << fixed << setprecision(15) << H * H * BMI / 100.0 / 100.0 << endl;
    return 0;
}