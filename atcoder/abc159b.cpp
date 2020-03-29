#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string s1 = s;
    string rs1 = s;
    reverse(rs1.begin(), rs1.end());
    string s2 = s.substr(0, (s.size()-1)/2);
    string rs2 = s2;
    reverse(rs2.begin(), rs2.end());
    string s3 = s.substr((s.size()+3)/2-1);
    string rs3 = s3;
    reverse(rs3.begin(), rs3.end());
    if (s1 == rs1 && s2 == rs2 && s3 == rs3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}