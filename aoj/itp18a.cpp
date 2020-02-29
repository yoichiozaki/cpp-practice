#include <bits/stdc++.h>
using namespace std;

int main(){
    // 0123... < ABCD... < abcd...
    char ch;
    while ((ch = getchar()) != EOF) {
        if ('a' <= ch && ch <= 'z') {
            cout << char(ch + ('A' - 'a'));
        } else if ('A' <= ch && ch <= 'Z') {
            cout << char(ch - ('A' - 'a'));
        } else {
            cout << ch;
        }
    }
}