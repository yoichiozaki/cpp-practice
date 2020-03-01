#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> cnt(100010, 0); // cnt.at(i)はXとしてa_iを選んだときにいくらかの操作を経た後にXと等しくなる項の数
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cnt.at(a+1)++;
        cnt.at(a)++;
        cnt.at(a+2)++;
    }
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    cout << cnt.at(0) << endl;
    return 0;
}
