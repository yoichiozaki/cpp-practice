#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    cout << ((B-A)%2 == 0 ? "Alice" : "Borys") << endl;
	return 0;
}
