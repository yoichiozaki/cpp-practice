#include <bits/stdc++.h>
using namespace std;

int main() {
    int S;
    cin >> S;
    cout << S/(60*60) << ":" << (S%(60*60))/60 << ":" << (S%(60*60))%60 << endl;
}