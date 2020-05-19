#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        if (!item.empty())
        {
            elems.push_back(item);
        }
    }
    return elems;
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        vector<string> in = split(s, ' ');
        stack<double> st;
        for (int i = 0; i < in.size(); i++)
        {
            if (in[i] == "+" || in[i] == "-" || in[i] == "*" || in[i] == "/")
            {
                double b = st.top();
                st.pop();
                double a = st.top();
                st.pop();
                if (in[i] == "+")
                    st.push(a + b);
                else if (in[i] == "-")
                    st.push(a - b);
                else if (in[i] == "*")
                    st.push(a * b);
                else if (in[i] == "/")
                    st.push(a / b);
            }
            else
            {
                st.push(stod(in[i]));
            }
        }
        cout << fixed << setprecision(12) << st.top() << endl;
    }
    return 0;
}