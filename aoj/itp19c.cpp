#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, taro = 0, hanako = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t, h;
        cin >> t >> h;
        if (t < h) {
            hanako += 3;
        } else if (h < t) {
            taro += 3;
        } else {
            taro += 1; hanako += 1;
        }
    }
    cout << taro << " " << hanako << endl;
    return 0;
}