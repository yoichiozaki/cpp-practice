#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 1;
    while (i <= 5) {
        cout << i << endl;
        i++
    }

    int N;
    cin >> N;
    int sum = 0;
    int x;
    int cnt = 0;
    while (cnt < N) {
        cin >> x;
        sum += x;
        cnt++;
    }
    cout << sum << endl;

    while (true) {
        cout << "hello" << "world" << endl;
    }

}
