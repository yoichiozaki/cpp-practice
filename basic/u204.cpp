#include <bits/stdc++.h>
using namespace std;

int make_doubled(int &x)
{
    x *= 2;
    return x;
}

void min_max(int a, int b, int c, int &minimum, int &maximum)
{
    minimum = min(a, min(b, c));
    maximum = max(a, max(b, c));
}

int sum100(vector<int> &a) 
{
    int result = 0;
    for (int i = 0; i < 100; i++) {
        result += a.at(i);
    }
    return result;
}

int main()
{
    int a = 3;
    int &b = a; // b is a reference of variable 'a';
    cout << a << endl;
    cout << b << endl; // ==> printing 3
    b = 4;
    cout << a << endl; // ==> printing 4
    cout << b << endl;
    
    string s = "apg4b";
    string &t = s;

    t.at(0) = 'A';
    t.at(1) = 'P';
    t.at(2) = 'G';
    
    cout << s << endl; // ==> printing "APG4b"
    cout << t << endl;

    int a = 123;
    int &b = a;
    int &c = b; // c is a reference to variable 'a'

    int x = 10;
    int x_doubled = make_doubled(x);
    cout << x << endl; // ==> printing "20"
    cout << x_doubled << endl; // ==> printing "20"

    // 参照の使い所: 複数の値を返す
    int minimum, maximum;
    min_max(3, 1, 5, minimum, maximum);
    cout << "minimum: " << minimum << endl;
    cout << "maximum: " << maximum << endl;

    // 参照の使い所: 無駄なコピーを減らす
    vector<int> vec(1000000000, 1);
    for (int i = 0; i < 500; i++) {
        cout << sum100(vec) << endl;
    }

    vector<int> vec1 = {1, 3, 2, 4};
    for (int &x : vec1) {
        x *= 2;
    } // ==> vec1 = {2, 6, 4, 8}
}
