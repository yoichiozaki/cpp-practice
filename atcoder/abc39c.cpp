#include <bits/stdc++.h>
using namespace std;

int main()
{
    string keyboard = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    vector<string> scale = {"Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si",
                            "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si",
                            "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si",
                            "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si"};
    string s;
    cin >> s;
    cout << scale[keyboard.find(s)] << endl;
    return 0;
}