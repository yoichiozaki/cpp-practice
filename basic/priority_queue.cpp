#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> Q;
    Q.push(1);
    Q.push(2);
    Q.push(-1);
    int x1 = Q.top();
    Q.pop();
    int x2 = Q.size();
    return 0;
}