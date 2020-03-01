#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> abc(3);
	cin >> abc.at(0)
        >> abc.at(1)
        >> abc.at(2);
	int ans = 0;
	while (1) {
        if (abc.at(0) == abc.at(1) && abc.at(1) == abc.at(2)) {
            break;
        }
		sort(abc.begin(), abc.end());
        if (abc.at(1) == abc.at(2)) {
            abc.at(0) += 2;
        } else {
            abc.at(0)++;
            abc.at(1)++;
        }
		ans++;
	}
	cout << ans << endl;
	return 0;
}
