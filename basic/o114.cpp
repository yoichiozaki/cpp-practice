#include <bits/stdc++.h>
using namespace std;

int main()
{
    int answer = min(10, 5);
    cout << answer << endl;

    answer = max(10, 5);
    cout << answer << endl;

    int c = 10, d = 11;
    swap(c, d);
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    vector<int> vec1 = {1, 3, 5, 2};
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1.at(i) << endl;
    }

    vector<int> vec2 = {4, 3, 6, 1};
    sort(vec2.begin(), vec2.end());
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2.at(i) << endl;
    }

    vector<int> vec3 = {2, 5, 2, 1};
    sort(vec3.begin(), vec3.end());
    reverse(vec3.begin(), vec3.end());
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3.at(i) << endl;
    }
}
