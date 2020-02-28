#include <bits/stdc++.h>
using namespace std;

int my_min(int x, int y)
{
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

void hello(string name)
{
    cout << "hello, " << name << endl;
    return;
}

int get_input()
{
    int x;
    cin >> x;
    return x;
}

int main()
{
    int answer = my_min(5, 10);
    cout << answer << endl;
}
