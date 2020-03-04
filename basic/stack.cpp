#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    int x1 = a.top();
    a.pop();
    a.push(4);
    a.push(5);
    int x2 = a.top();
    int x3 = a.size();
    int x4 = (a.empty() ? 100 : 200);
    return 0;
}