#include <bits/stdc++.h>
using namespace std;

int top, S[1000];

void push(int x) {
    top++;
    S[top] = x;
}

int pop() {
    top--;
    return S[top+1];
}

int main() {
    int a, b;
    top = 0;
    char s[100];
    while (scanf("%s", s) != EOF) {
        if (s[0] == '+') {
            a = pop(); b = pop();
            push(a+b);
        } else if (s[0] == '-') {
            b = pop(); a = pop();
            push(a-b);
        } else if (s[0] == '*') {
            a = pop(); b = pop();
            push(a*b);
        } else {
            push(atoi(s));
        }
    }
    cout << pop() << endl;
    return 0;
}