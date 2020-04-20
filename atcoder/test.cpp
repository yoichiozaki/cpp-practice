#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  stack<int> st;
  while (cin >> s) {
    if (s == "|") break;
    int a, b;
    if (s == "+") {
      b = st.top(); st.pop();
      a = st.top(); st.pop();
      st.push(a + b);
    } else if (s == "-") {
      b = st.top(); st.pop();
      a = st.top(); st.pop();
      st.push(a - b);
    } else if (s == "*") {
      b = st.top(); st.pop();
      a = st.top(); st.pop();
      st.push(a * b);
    } else if (s == "/") {
      b = st.top(); st.pop();
      a = st.top(); st.pop();
      st.push(a / b);
    } else {
      st.push(stoi(s));
    }
  }
  cout << st.top() << endl;
  return 0;
}