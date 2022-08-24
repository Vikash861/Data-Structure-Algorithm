#include <bits/stdc++.h>
using namespace std;


int main()
{
    stack<char>st;
    string name = "vikash";
    string ans = "";
    for (int i = 0; i < name.length(); i++)
    {
        char ch = name[i];
        st.push(ch);
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans << endl;


}