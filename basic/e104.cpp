#include <bits/stdc++.h>
using namespace std;

int main()
{
    int name;
    name = 10;

    // int name = 10;

    cout << name << endl;
    cout << name + 2 << endl;
    cout << name * 3 << endl;

    int a = 10;
    int b;

    b = a;
    a = 5;

    cout << a << endl;
    cout << b << endl;

    int c = 10, d = 5; // 複数の変数の同時宣言も可能

    int i = 30;
    double d = 1.5;
    string s = "hello!";

    cout << i + d << endl; // ==> 31.5
    cout << i * d << endl; // ==> 45
    cout << 45 / 2 << endl; // ==> 22
    cout << i * d / 2 << endl; // ==? 22.5

}