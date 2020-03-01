#include<bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        ans += tmp;
    }
    cout << (ans%2 == 0 ? "YES" : "NO") << endl;
	return 0;
}
