#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, s1, p;
	cin >> s;
	int q;
	cin >> q;
	while (q--){
		cin >> s1;
		if (s1 == "replace"){
			int	a, b;
			cin >> a >> b >> p;
			int k = 0;
			for (int i = a; i <= b; i++){
				s[i] = p[k];
				k++;
			}
		} else if (s1 == "reverse"){
			int	a, b;
			cin >> a >> b;
			int j = b;
			for (int i = a; i <j; i++){
				swap(s[j],s[i]);
				j--;
			}
		} else{
			int	a, b;
			cin >> a >> b;
			for (int i = a; i <= b; i++){
				cout << s[i];
			}
			cout << endl;
		}
	}
}