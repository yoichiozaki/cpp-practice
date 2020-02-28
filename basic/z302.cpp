#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<string, int> p("abc", 3);
    cout << p.first << endl;
    p.first = "hello";
    cout << p.first << endl;
    cout << p.second << endl;

    p = make_pair("***", 1); // ペアの作成

    string s;
    int a;
    tie(s, a) = p; // ペアの分解
    cout << s << endl;
    cout << a << endl;
    
    tuple<int, string, bool> data(1, "hello", true);
    get<2>(data) = false; // 0-originでデータにアクセス
    cout << get<1>(data) << endl; // printing "hello"
    data = make_tuple(2, "world", true);
    int ta;
    string ts;
    bool tb;
    tie(ta, ts, tb) = data;
    cout << ta << " " << ts << " " << tb << endl;
    tie(ignore, ignore, tb) = data;
    cout << tb << endl;

    pair<int, int> a(3, 1);
    pair<int, int> b(2, 10);

    // pair同士，tuple同士の比較ができる => ソートもできる
    if (a < b) {
        cout << "a < b" << endl;
    } else {
        cout << "b < a" << endl;
    }
    
    // autoで型推論
    string a = "Hello, ";
    string b = "world";
    auto ab = concat(a, b);
    cout << ab << endl;

    vector<int> c = {1, 2, 3};
    auto d = c;
    for (auto elem : d) {
        cout << elem << endl;
    }

    // type alias
    using pii = pair<int, int>
}
