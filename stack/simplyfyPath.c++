#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    stack<string>st;
    string ans;
    for(int i = 0; i < path.length(); i++) {
        if(path[i] == '/'){
            continue;
        }
        string temp;
        while(i < path.length() && path[i] != '/'){
            temp += path[i];
            i++;
        }
        if(temp == "."){
            continue;
        }
        else if(temp == ".."){
            if(!(st.empty())){
                st.pop();
            }
        }
        else{
            st.push(temp);
        }
    }
    while(!st.empty()){
        ans = "/"+st.top() + ans;
        st.pop();
    }
    if(ans.length() == 0){
        ans = "/";
    }
    return ans;
}


int main()
{
    cout << simplifyPath("/home//foo/");

}