#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1;
    str2 = "hogehoge";
    cout << str1 << " " << str2 << endl;

    cout << str1.size() << endl;

    cout << str1.at(0) << endl;
    cout << str1.at(str.size() - 1) << endl;

    char c = 'a';
    cout << c << endl;

    char d = str1.at(0);
    cout << d << endl;

    string input;
    cin >> input;
    int cnt = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input.at(i) == 'O') {
            cnt++;
        }
    }
    cout << cnt << endl;

    cout << "hello"s.size() << endl; // リテラルなstringに対してメソッドを適用するときは末尾にsをつける

    string s1 = "abc";
    string s2 = "abc";
    string s3 = "xy";

    if (s1 == s2) {
        cout << "s1 == s2" << endl;
    }

    // C++での文字の辞書順は数字<大文字<小文字の順
    if (s1 < s3) {
        cout < "abc < xy" << endl;
    }

    string hello = "hello";
    cout << hello + " world" << endl;
    hello += " world";
    cout << hello << endl;

    string str = "a";
    char a = 'a';
    // bool b = str == c; // だめ

    cout << str + c << endl; // これはできる

    char O, K;
    cin >> O >> K;
    cout << O << endl;
    cout << K << endl;

    cout << "hello\nworld\n\t!";

    string l1, l2;
    getline(cin, l1); // 一行入力
    getline(cin, l2);


}
