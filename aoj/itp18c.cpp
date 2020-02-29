#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char, int> res;
    char ch;
    for (char x = 'a'; x <= 'z'; x++) {
        res[x] = 0;
    }
    // 0123... < ABCD... < abcd...
    while (cin >> ch) {
        if ('A' <= ch && ch <= 'Z') {
            res[ch - 'A' + 'a']++;
        } else if ('a' <= ch && ch <= 'z') {
            res[ch]++;
        } else {
            continue;
        }
    }
    for (auto p : res) {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}